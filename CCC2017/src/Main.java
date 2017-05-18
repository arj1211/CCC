import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int findLargestSumPair(int arr[], int n) {
		// Initialize first and second largest element
		int first, second;
		if (arr[0] > arr[1]) {
			first = arr[0];
			second = arr[1];
		} else {
			first = arr[1];
			second = arr[0];
		}

		// Traverse remaining array and find first and second largest
		// elements in overall array
		for (int i = 2; i < n; i++) {
			/*
			 * If current element is greater than first then update both first
			 * and second
			 */
			if (arr[i] > first) {
				second = first;
				first = arr[i];
			}

			/* If arr[i] is in between first and second then update second */
			else if (arr[i] > second && arr[i] != first)
				second = arr[i];
		}
		return (first + second);
	}

	public static long choose(int x, int y) {
		if (y < 0 || y > x)
			return 0;
		if (y > x / 2) {
			// choose(n,k) == choose(n,n-k),
			// so this could save a little effort
			y = x - y;
		}

		long answer = 1;
		for (int i = 1; i <= y; i++) {
			answer *= (x + 1 - i);
			answer /= i;
		}
		return answer;
	}

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {

		int N = sc.nextInt();

		int[] wood = new int[N];

		for (int i = 0; i < N; i++)
			wood[i] = sc.nextInt();

		int [] ws = wood;
		Arrays.sort(ws);
		
		int maxSum = ws[ws.length-1]+ws[ws.length-2];
		
		
		int[] freqSum = new int[maxSum+1];
		
		for (int i = 0; i < freqSum.length; i++)
			freqSum[i] = 0;
		
		for (int i = 0; i < wood.length; i++) {
			for (int j = i + 1; j < wood.length; j++) {
				freqSum[wood[i] + wood[j]]++;
			}
		}
		
		//for (int i:freqSum) System.out.println(i);
		
		int highestFreq = 0;
		for (int i : freqSum) {
			if (highestFreq < i)
				highestFreq = i;
		}
		
		Arrays.sort(freqSum);
		
		int ways=0;
		for (int i=freqSum.length-1;i>=0;i--)
		{
			if (freqSum[i]==highestFreq) ways++;
		}
		
		System.out.print(highestFreq + " " + /*choose(N, highestFreq * 2)*/ways);
	}
}