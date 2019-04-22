import java.util.*;
import java.math.BigInteger;

public class lg2152
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigInteger a = cin.nextBigInteger(), b = cin.nextBigInteger();
        cin.close();

        System.out.println(a.gcd(b));
    }
}
