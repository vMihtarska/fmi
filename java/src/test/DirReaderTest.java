package test;

import static org.junit.Assert.*;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import org.junit.Test;


import src.DirReader;

public class DirReaderTest {

	@Test
	public void readDirTree() {
		String rootDir = "D:/Desktop/testfiles/";
		
		DirReader dir = new DirReader();
		List<Path> paths = null;
		List<Path> expectedPaths = new ArrayList<Path>();
		expectedPaths.add(Paths.get(rootDir + "1.txt"));
		expectedPaths.add(Paths.get(rootDir + "2.txt"));
		expectedPaths.add(Paths.get(rootDir + "3.txt"));
		expectedPaths.add(Paths.get(rootDir + "4.txt"));
		expectedPaths.add(Paths.get(rootDir + "5.txt"));
		expectedPaths.add(Paths.get(rootDir + "fsa.txt"));
		expectedPaths.add(Paths.get(rootDir + "gds.txt"));
		expectedPaths.add(Paths.get(rootDir + "movies-mpaa.txt"));
		expectedPaths.add(Paths.get(rootDir + "otherdir/6.txt"));
		expectedPaths.add(Paths.get(rootDir + "otherdir/otherdir/7.txt"));
		
		try {
			paths = dir.readDirTree(Paths.get("D:/Desktop/testfiles"));
		} catch (Exception e) {
			fail(e.getMessage());
		}
		
		assertTrue(paths.equals(expectedPaths));
		
	}

}
