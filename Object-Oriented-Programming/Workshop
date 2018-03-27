import java.io.*;
import java.util.*;
class Workshop
{
  int total_number;
  int num_of_machines;


  //Methods
  Workshop(){
    total_number=0;
    num_of_machines=3;
  }
  public Vehicle Get_Vehicle(Vehicle A){
    total_number+=1;
    //TO BE RANDOM
      A.color="red";
      A.engine=5;
      A.suspension=5;
      A.engine_condition=false;
    return A;
  }

  public Vehicle Repair(Vehicle A)
  {
    if(A.engine_condition==false)
    {
      //Repaired engine
      System.out.println("Repaired Engine!");
      A.engine_condition=true;

    }
      return A;
  }

  public Vehicle change_colour(Vehicle A)
  {
    //Changed Color
    Scanner sc=new Scanner(System.in);
    String newcol = sc.nextLine();
    A.color = newcol;
    System.out.println("Changed colour to  "+newcol);
    return A;
  }

  public Vehicle upgrade_engine(Vehicle A)
  {
    //Changed Color
    A.engine=A.engine+1;
    System.out.println("Upgraded engine to level  "+A.engine);
    return A;
  }

}

class Vehicle
{
  String color; //
  int engine; // 0 -10
  int suspension; // 0 -10
  boolean engine_condition; //true for working

  public void printDetails(){
    System.out.println("Color:"+color);
    System.out.println("Engine: "+engine);
    System.out.println("Suspension: "+suspension);
    System.out.println("Engine Condn: "+engine_condition);
  }

}

/*class Bike extends Vehicle
{
  int fuel;
  int fuelmax;
}*/
public class Execute{
    public static void main(String args[]){
      Vehicle A=new Vehicle();
      Workshop W=new Workshop();
      A=W.Get_Vehicle(A);
      A=W.change_colour(A);
      A=W.upgrade_engine(A);
      A=W.Repair(A);
      A.printDetails();
    }
}
