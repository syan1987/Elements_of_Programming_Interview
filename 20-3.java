
public class Test {
	private Number n = new Number();
	private Thread thread1 = new ThreadPrintOdd();
	private Thread thread2 = new ThreadPrintEven();
	public Test () {
		thread1.start();
		thread2.start();
	}
	
	class ThreadPrintEven extends Thread {
		public void run() {
			n.printEven();
		}
	}
	class ThreadPrintOdd extends Thread {
		public void run() {
			n.printOdd();
		}
	}
	
	class Number {
		private int current = 1;
		public synchronized void printOdd() {
			while (current<=100) {
				System.out.println(current);
				current++;
				notify();
				if (current>100) break;
				while (current%2==0) {
					System.out.println("waiting for even");
					try {
						wait();
					}
					catch(InterruptedException ex) {
						ex.printStackTrace();
					}				
				}

			}
		}
		public synchronized void printEven() {
			while (current<=100) {
				System.out.println(current);
				current++;
				notify();
				if (current>100) break;
				while (current%2==1) {
					System.out.println("waiting for odd");
					try {
						wait();
					}
					catch(InterruptedException ex) {
						ex.printStackTrace();
					}				
				}
			}
		}
	}
	
	public static void main(String[] args) {
	    Test t = new Test();
		System.out.println("END");

    }

}
