import java.util.Arrays;
import java.util.Scanner;

//Arrays.sort(arr);
public class Main {

	static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) {

		int N = scan.nextInt();

		int lowS = N / 2, highS = N / 2;
		if (N % 2 != 0)
			lowS++;

		int[] inArr = new int[N], lowArr = new int[lowS], highArr = new int[highS];

		for (int i = 0; i < inArr.length; i++)
			inArr[i] = scan.nextInt();

		Arrays.sort(inArr);

		for (int i = 0; i < inArr.length / 2; i++) {
			System.out.print(inArr[inArr.length / 2 - 1 - i] + " "
					+ inArr[inArr.length / 2 + i] + " ");
		}

		//
		// for (int i = lowArr.length - 1; i >= 0; i--)
		// lowArr[i] = inArr[lowArr.length - i - 1];
		//
		// for (int i = 0; i < highArr.length; i++)
		// highArr[i] = inArr[highArr.length + i];
		//
		// for (int i = 0; i < lowArr.length; i++) {
		// System.out.print(lowArr[i]+" ");
		// System.out.print(highArr[i]+" ");
		// }

	}

}
