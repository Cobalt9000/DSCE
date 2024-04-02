package com.example;
import java.io.*;
import java.net.*; 

public class FileServer {
	public static void main(String[] args)
	{
	new FileServer();
	}
	public FileServer()
	{
	try
	{
	ServerSocket serversocket=new ServerSocket(8000); System.out.println("Server Started	");
	System.out.println("	");
	Socket socket=serversocket.accept();
	DataInputStream input=new DataInputStream(socket.getInputStream());
	DataOutputStream output=new DataOutputStream(socket.getOutputStream());
	String str=input.readUTF();
	System.out.println("Requested File Name:"+str);
	System.out.println("	");
	String everything; 
	try {
	InputStream in= new FileInputStream(str);
	BufferedReader reader= new BufferedReader(new InputStreamReader(in));
	StringBuilder out = new StringBuilder();
	String line;
	System.out.println("Reading Contents of the File...");
	System.out.println("	");
	while ((line= reader.readLine()) != null)
	{
	out.append(line+"\n");
	}
	everything= out.toString(); System.out.println("File Contents sent to client...");
	System.out.println("	");
	}
	catch(Exception ex)
	{
	everything="File Not Found!";
	}
	output.writeUTF(everything);
	}
	catch(Exception ex)
	{
	ex.printStackTrace();
	}
	}
}

