package test;

import org.junit.Test;

import static org.junit.Assert.*;

import java.nio.file.Path;
import java.nio.file.Paths;

import src.Line;
import src.Product;
import src.Consumer;
import src.Store;

public class ConsumerTest {

	@Test
	public void consumerTest() {
		Path filename = Paths.get("D:/Desktop/testfiles/otherdir/6.txt");
		Store<Line> store = new Store<Line>();
		Consumer consumer = new Consumer(store, "a");
		
		store.setCountUnfinishedProducers(1);
		store.add(new Product<Line>(new Line("asd", filename, 0)));
		store.add(new Product<Line>(new Line("f", filename, 0)));
		store.add(new Product<Line>(new Line("aa", filename, 0)));
		
		consumer.start();
		
		try {
			Thread.sleep(1500);
		} catch (InterruptedException e) {
			fail(e.getMessage());
		}
		
		synchronized (store) {
			store.setCountUnfinishedProducers(0);
			store.notifyAll();
		}
		
		assertTrue(store.isEmpty());
	}

}
