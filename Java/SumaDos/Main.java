import java.io.*;

public class Main{
	public static void main(String[]args){

		String command = "java Adder";
		String input = "10\n";

		Runtime runtime = Runtime.getRuntime();
		Process process;

		try{
			process = runtime.exec(command);

			// OutputStream os = process.getOutputStream();
			// os.write(input.getBytes());
			// os.flush();
		}catch(IOException ioex){
			ioex.printStackTrace();
		}
	}
}