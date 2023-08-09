package Multi_Inheritance;

//Child.java
public class Child extends Parent {
 public void bike() {
     System.out.println("Bike");
 }
 
 public static void main(String[] args) {
     Child c = new Child();
     c.house();
     c.car();
     c.bike();
     c.garden();
 }
}

