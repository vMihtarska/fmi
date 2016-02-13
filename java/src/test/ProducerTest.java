package test;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

import src.Line;
import src.Producer;
import src.Store;

public class ProducerTest {

	@Test
	public void produceTest() {
		Path filename = Paths.get("D:/Desktop/testfiles/otherdir/6.txt");
		
		Store<Line> store = new Store<Line>();
		Producer producer = null;
		List<Line> lines = new ArrayList<Line>();
		
		lines.add(new Line("Other dir", filename, 1));
		lines.add(new Line("Sixth", filename, 2));
		lines.add(new Line("File", filename, 3));
		lines.add(new Line("Blq", filename, 4));
		lines.add(new Line("File", filename, 5));
		lines.add(new Line("GG", filename, 6));
		lines.add(new Line("File", filename, 7));
		
		try {
			producer = new Producer(filename, store);
		} catch (Exception e) {
			fail(e.getMessage());
		}
		
		producer.start();
		
		boolean threw = false;
		
		try {
			for (int i = 0; ; i++) {
				Line line = store.consume().getProduct();
				assertTrue(lines.get(i).lineEquals(line));
			}
		} catch (Exception e) {
			threw = true;
		}

		assertTrue("Should have thrown", threw);
	}

}
