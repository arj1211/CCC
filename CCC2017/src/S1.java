import java.util.Scanner;


public class S1 {

	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {
	
		int N= scan.nextInt();
		
		int[] swiftRuns = new int[N+1], semaRuns = new int[N+1];
		
		for (int i=1;i<=N;i++)
			swiftRuns[i]=scan.nextInt();
		for (int i=1;i<=N;i++)
			semaRuns[i]=scan.nextInt();
		
		int K=0;
		int swiftSum=0,semaSum=0;
		for (int run=1;run<=N;run++)
		{
			swiftSum+=swiftRuns[run];
			semaSum+=semaRuns[run];
			if (swiftSum==semaSum)
				K=run;
		}
		System.out.println(K);
	}

}
