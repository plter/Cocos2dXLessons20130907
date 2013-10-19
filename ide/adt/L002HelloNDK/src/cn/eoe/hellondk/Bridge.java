package cn.eoe.hellondk;

public class Bridge {

	public native int getNum();
	
	public void showMsg(){
		System.out.println("Hello eoe");
	}
	
	public static native void callC();
	
	public static void staticShowMsg(String name){
		System.out.println("Hello "+name);
	}
//	public native String getWords();
}
