#ifndef REQUEST_H
#define REQUEST_H
struct request;

struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
#endif
