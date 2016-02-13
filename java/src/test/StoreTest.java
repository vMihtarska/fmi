package test;

import static org.junit.Assert.*;

import org.junit.Test;

import src.Line;
import src.Product;
import src.Store;

public class StoreTest {

	@Test
	public void fillStore() {
		Store<Line> store = new Store<Line>();
		
		assertTrue("Should be able to add", store.canAdd());
		
		for (int i = 0; i < Store.MAX_PRODUCTS; i++) {
			store.add(new Product<Line>(new Line("", null, 0)));
		}

		assertFalse("Should not be able to add", store.canAdd());
		
		store.consume();
		
		assertTrue("Should be able to add", store.canAdd());
		
		boolean threw = false;
		
		try {
			while (true) {
				store.consume();
			}
		} catch (Exception e) {
			threw = true;
		}
		
		assertTrue("Should have thrown", threw);
	}
}
