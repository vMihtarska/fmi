package src;
public class ConsumersDispatcher {
	private String searchArgument;
	private Store<Line> store;
	private int consumersCount;
	
	public ConsumersDispatcher(Store<Line> store, String searchArgument, int count) {
		this.searchArgument = searchArgument;
		this.store = store;
		this.consumersCount = count;
	}
	
	public void dispatch() {
		for (int i = 0; i < consumersCount; i++) {
			Consumer consumer = new Consumer(store, searchArgument);
			consumer.start();
		}
	}
}
