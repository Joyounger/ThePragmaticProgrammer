
import java.lang.System; // for exit()
import java.lang.Thread; // for dumpStack()

public class Assert {
	// write a messagfe, print a stack trace and exit if
	// our parameter is false.
	public static void TEST(boolean condition) {
		if (!condition) {
			System.out.println("==== Assertion Failed ====");
			Thread.dumpStack();
			System.exit(1);
		}
	}

	// Testbed. if our parameter id 'okay', try an assertion that 
	// succeeds, if 'fail' try one that fails.
	public static void main(String[] args) {
		if (args[0].compareTo("okay") == 0) {
			TEST(1 == 1);
		} else if (args[0].compareTo("fail") == 0) {
			TEST(1 == 2);
		} else {
			throw new RuntimeException("vad argument");
		}
	}	
}


/*
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 0
        at Assert.main(Assert.java:19)
*/