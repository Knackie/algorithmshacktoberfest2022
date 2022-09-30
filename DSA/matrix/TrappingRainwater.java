package matrix;

public class TrappingRainwater {
	public static int TrappingWater(int a[]) {
		int n=a.length;
		int leftMax=0,rightMax=0, ans=0;
		int left=0,right=n-1;
		while(left<right) {
			if(a[left]<=a[right]) {
				if(a[left]>=leftMax) leftMax=a[left];
				else ans+=(leftMax-a[left]);
					left++;
			}else {
				if(a[right]>=rightMax) rightMax=a[right];
				else ans+=(rightMax-a[right]);
				right--;
			}
		}
		return ans;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int arr[]= {3,4,5,1,7,2,6,5,4,1};
		int ans= TrappingWater(arr);
		System.out.println(ans);
	}

}
