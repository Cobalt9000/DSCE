package Hirarchial_Inheritance;

public class Main {
    public static void main(String[] args) {
        Car car = new Car();
        car.start();
        car.drive();
        car.stop();
        
        System.out.println();
        
        Motorcycle motorcycle = new Motorcycle();
        motorcycle.start();
        motorcycle.ride();
        motorcycle.stop();
    }
}

