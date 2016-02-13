package src;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		System.out.println("Enter the search word:");
		Scanner scanner = new Scanner(System.in);
		String inputString = scanner.next();
		System.out.println("Enter the path:");
		String filePath = scanner.next();
		scanner.close();
		
		Store<Line> store = new Store<Line>();
		DirReader dr = new DirReader();
		List<Path> filePaths = dr.readDirTree(Paths.get(filePath));
		store.setCountUnfinishedProducers(filePaths.size());
		
		ConsumersDispatcher cd = new ConsumersDispatcher(store, inputString, 10);
		cd.dispatch();
		
		
		ProducersDispatcher pd = new ProducersDispatcher(filePaths, store);
		pd.dispatch();
		
	}
}
