

Balancing Resources with C++ Exceptions
bad
```cpp
void doSomething(void) {
Node *n = new Node;
try {
// do something
}
catch (...) {
delete n;
throw;
}
delete n;
}
```

good manner
```cpp
void doSomething1(void) {
Node n;
try {
// do something
}
catch (...) {
throw;
}
}
```



If the switch from a pointer is not possible, the same effect can be achieved by wrapping the resource (in this case, a Node pointer) within another class.  
```cpp
// Wrapper class for Node resources
class NodeResource {
    Node *n;
    public:
    NodeResource() { n = new Node; }
    ~NodeResource() { delete n; }
    Node *operator->() { return n; }
};

void doSomething2(void) {
    NodeResource n;
    try {
    // do something
    }
    catch (...) {
        throw;
    }
}
```

Because this technique is so useful, the standard C++ library provides the template class
auto_ptr, which gives you automatic wrappers for dynamically allocated objects.
```cpp
void doSomething3(void) {
auto_ptr<Node> p (new Node);
// Access the Node as p->...
// Node automatically deleted at end
}
```

good manner
```java
public void doSomething() throws IOException {
File tmpFile = new File(tmpFileName);
FileWriter tmp = new FileWriter(tmpFile);
try {
// do some work
}
finally {
    tmpFile.delete();
}
}
```
