#include <stdio.h>
#include <stdlib.h>
struct Given {
int id;
int all[3];
int Max[3];
int need[3];
};
void banker_algo() {
int n, m;
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter the number of resources: ");
scanf("%d", &m);
struct Given* given = (struct Given*)malloc(n * sizeof(struct Given));
int* avail = (int*)malloc(m * sizeof(int));
int* finish = (int*)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
printf("Enter the allocation for process %d resource %d: ", i, j);
scanf("%d", &given[i].all[j]);
}
for (int j = 0; j < m; j++) {
printf("Enter the maximum need for process %d resource %d: ", i, j);
scanf("%d", &given[i].Max[j]);
}
for (int j = 0; j < m; j++) {
given[i].need[j] = given[i].Max[j] - given[i].all[j];
}
}
for (int j = 0; j < m; j++) {
printf("Enter the available amount of resource %d: ", j);

scanf("%d", &avail[j]);
}
for (int i = 0; i < n; i++) {
finish[i] = 0;
}
int k = 0;
int flag = 0;
while (k < n) {
flag = 0;
for (int i = 0; i < n; i++) {
if (finish[i] == 0) {
flag = 0;
for (int j = 0; j < m; j++) {
if (given[i].need[j] > avail[j]) {
flag = 1;
break;
}
}
if (flag == 0) {
for (int j = 0; j < m; j++) {
avail[j] += given[i].all[j];
}
finish[i] = 1;
printf("\nProcess %d is completed\n", i);
}
}
}
if (flag == 1) {
break;
}
k++;
}
if (k == n) {
printf("\nAll processes are completed safely\n");
} else {
printf("\nDeadlock detected\n");
}
// Free allocated memory
free(given);
free(avail);

free(finish);
}
int main() {
banker_algo();
return 0;
}