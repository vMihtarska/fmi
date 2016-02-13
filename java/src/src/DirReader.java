package src;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class DirReader {
	private List<Path> fileNames;
	
	public DirReader() {
		 fileNames = new ArrayList<>();
	}
	
	public List<Path> readDirTree(Path path) throws IOException, FileNotFoundException {
		DirectoryStream<Path> dirs = Files.newDirectoryStream(path);
		
		for (Path dir : dirs) {
			try (BufferedReader logFileReader = new BufferedReader(new FileReader(dir.toString()))) {
				fileNames.add(dir);
		    } catch (FileNotFoundException e) {
		    	if (Files.isDirectory(dir)){
					readDirTree(dir);
				}
			}
		}
		
		return fileNames;
	}
	
	public List<Path> getFileNames() {
		return fileNames;
	}
}
