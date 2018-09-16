





###### 练习

2-6
设计一种解析时间规范的BNF文法,能接受下面的所有例子:
4pm,  7:38pm,  23:42,  3:16,  3:16am

A:使用BNF,可以这样编写时间规范
```
<item> ::= <hour> <ampm> |
           <hour> : <minute> <ompm> |
           <hour> : <minute>
<ampm> ::= am | pm
<hour> ::= <digit> |
           <digit> <digit>
<minute> :: = <digit> <digit>
<digit> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
```



