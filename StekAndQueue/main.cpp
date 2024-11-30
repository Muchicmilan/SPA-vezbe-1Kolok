#include "stack.h"
#include "queue.h"
#include "queueImplementationWithStack.h"

void reverseQueue(Queue** queue) {
    Stack* stack = createStack();
    while (!isEmpty(*queue))
        push(&stack, pop(queue));
    while (!isEmpty(stack))
        push(queue, pop(&stack));
    deleteStack(&stack);
}

int main() {
    Queue* queue = createQueue();
    push(&queue, 10);
    push(&queue, 20);
    push(&queue, 30);
    push(&queue, 40);
    push(&queue, 50);
    display(queue);
    reverseQueue(&queue);
    display(queue);
    return 0;
}
