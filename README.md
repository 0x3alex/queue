# queue
generic queue implementation in c

The pointer, which is set, after calling 
```c
new_queue_...
````
will always point to the head of the queue, except when set to another address manually

# config options
```c
bool print_with_ptr_queue_##suffix = false;
```
