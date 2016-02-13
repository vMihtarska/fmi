package src;
import java.nio.file.Path;

public class Line {
	private String line;
	private Path filePath;
	private int lineNo;
	
	public Line (String line, Path filePath, int lineNo) {
		this.line = line;
		this.filePath = filePath;
		this.lineNo = lineNo;
	}

	public String getLine() {
		return line;
	}
	
	@Override
	public String toString() {
		return filePath.toString() + ", " + lineNo + ", " + line;
	}

	public boolean lineEquals(Line o) {
		return line.equals(o.line) && filePath.toString().equals(o.filePath.toString()) && lineNo == o.lineNo;
	}
}
