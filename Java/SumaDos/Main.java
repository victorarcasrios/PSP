import java.io.*;

public class Main{
	public static void main(String[]args){

		final String COMMAND = "java Adder";
		final String INPUT = "10\n";
		String line;

		Runtime runtime = Runtime.getRuntime();
		Process process;

		try{
			process = runtime.exec(COMMAND);

			OutputStream os = process.getOutputStream();
			for(int i = 0; i < 2; i++){
				os.write(INPUT.getBytes());
				os.flush();
			}

			InputStream is = process.getInputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));

			while((line = br.readLine()) != null)
				System.out.println(line);
			br.close();
		}catch(IOException ioex){
			ioex.printStackTrace();
		}
	}
}