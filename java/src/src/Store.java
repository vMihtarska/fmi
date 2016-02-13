package src;
import java.util.LinkedList;
import java.util.Queue;

public class Store<T> {
	public static int MAX_PRODUCTS = 1000;
	private int countUnfinishedProducers;
	
	private Queue<Product<T>> container;
	
	public Store() {
		container = new LinkedList<Product<T>>();
		countUnfinishedProducers = 0;
	}
	
	public void setCountUnfinishedProducers(int countUnfinishedProducers) {
		this.countUnfinishedProducers = countUnfinishedProducers;
	}
	
	public int getCountUnfinishedProducers() {
		return this.countUnfinishedProducers;
	}
	
	public Product<T> consume() {
		return container.remove();
	}

	public boolean add(Product<T> entry) {
		if (container.size() < MAX_PRODUCTS) {
			container.add(entry);
			return true;
		}
		
		return false;
	}
	
	public boolean canAdd() {
		return container.size() < MAX_PRODUCTS ;
	}
	
	public boolean isEmpty() {
		return container.isEmpty();
	}
	
}
