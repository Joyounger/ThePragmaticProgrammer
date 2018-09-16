



ex25 

bad manner
```java
public void showBalance(BankAccount acct) {
    Money amt = acct.getBalance();
    printToScreen(amt.printFormat());
}
```

good manner
```java
public void showBalance(BankAccount b) {
    b.printBalance();
}
```

