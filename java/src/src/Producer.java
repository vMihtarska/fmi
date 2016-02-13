package src;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.nio.file.Files;
import java.nio.file.Path;

public class Producer extends Thread {
	private Path filePath;
	private Store<Line> store;

	private BufferedReader fileReader;
	private int lineNo;
	
	public Producer(Path filePath, Store<Line> store) throws FileNotFoundException {
		this.filePath = filePath;
		this.store = store;
		
		fileReader = new BufferedReader(new FileReader(filePath.toString()));
		lineNo = 1;
	}
	
	private Product<Line> produce() {
		
		if (Files.isRegularFile(filePath)){
			try {
				return new Product<Line>(new Line(fileReader.readLine(), filePath, lineNo++));
			} catch (Exception e) {
				System.out.println(e.getMessage());
				e.printStackTrace();
			}
        }
		
		return null;
	}
	
	@Override
	public void run() {
		while (true) {
			Product<Line> product = produce();
			
			if (product.getProduct().getLine() == null) {
				synchronized (store) {
					store.setCountUnfinishedProducers(store.getCountUnfinishedProducers() - 1);
					if (store.getCountUnfinishedProducers() == 0) {
						store.notifyAll();
					}
				}
				
				return;
			}
			
			synchronized (store) {
				if (!store.add(product)) {
					try {
						store.wait();
					} catch (InterruptedException e) {
					}
				}
				
				store.notify();
			}
		}
	}
}
