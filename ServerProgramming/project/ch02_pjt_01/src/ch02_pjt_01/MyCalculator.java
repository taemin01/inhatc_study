package ch02_pjt_01;

public class MyCalculator {
    public void calAdd(int fNum, int sNum) {
        ICalculator calculator = new CalAdd();
        int value = calculator.doOperation(fNum, sNum);
        System.out.println("result : " + value);
    }

    public void calSub(int fNum, int sNum) {
        ICalculator calculator = new CalSub();
        int value = calculator.doOperation(fNum, sNum);
        System.out.println("result : " + value);
    }

    public void calMul(int fNum, int sNum) {
        ICalculator calculator = new CalMul();
        int value = calculator.doOperation(fNum, sNum);
        System.out.println("result : " + value);
    }

    public void calDiv(int fNum, int sNum) {
        ICalculator calculator = new CalDiv();
        int value = calculator.doOperation(fNum, sNum);
        System.out.println("result : " + value);
    }
}
