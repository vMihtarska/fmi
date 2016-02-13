package src;

public class Consumer extends Thread {
	private String searchArgument;
	private Store<Line> store;
	
	public Consumer(Store<Line> store, String searchArgument) {
		this.searchArgument = searchArgument;
		this.store = store;
	}
	
	private void consume(Product<Line> product) {
		/*Matcher matcher = searchPattern.matcher(product.getProduct().getLine());
		
		if (matcher.find()) {
			System.out.println("Found " + searchPattern.pattern() + " in " + product.getPayload().toString());
		}*/
		
		if(product.getProduct().getLine().contains(searchArgument)){
			System.out.println("Found " + searchArgument + " in " + product.getProduct().toString());
		}
	}
	
	@Override
	public void run() {
		while (true) {
			synchronized (store) {
				while (!store.isEmpty()) {
					consume(store.consume());
					if (store.canAdd()) {
						store.notify();
					}
				}
				
				if (store.isEmpty() && store.getCountUnfinishedProducers() == 0) {
					return;
				}

				try {
					while (store.isEmpty() && store.getCountUnfinishedProducers() > 0) {
						store.wait();
					}
					
				} catch (InterruptedException e) {
					
				}
			}
		}
	}
}
