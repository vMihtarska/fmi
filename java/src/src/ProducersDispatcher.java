package src;
import java.io.FileNotFoundException;
import java.nio.file.Path;
import java.util.List;

public class ProducersDispatcher {
	private List<Path> filePaths;
	private Store<Line> store;
	
	public ProducersDispatcher(List<Path> filePaths, Store<Line> store) {
		this.filePaths = filePaths;
		this.store = store;
	}
	
	public void dispatch() throws FileNotFoundException {
		for (Path path : filePaths) {
			Producer producer = new Producer(path, store);
			producer.start();
		}
	
	}
}
