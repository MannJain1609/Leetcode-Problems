Approach: Subtree Sum and Count
Intuition

Let ans be the returned answer, so that in particular ans[x] be the answer for node x.

Naively, finding each ans[x] would take O(N) time (where N is the number of nodes in the graph), which is too slow. This is the motivation to find out how ans[x] and ans[y] are related, so that we cut down on repeated work.

Let's investigate the answers of neighboring nodes x and y. In particular, say xy is an edge of the graph, that if cut would form two trees X (containing x) and Y (containing y).

![image](https://user-images.githubusercontent.com/75989468/177782034-08c4633b-9f0b-460c-b75b-e3d00f04fb16.png)

Then, as illustrated in the diagram, the answer for x in the entire tree, is the answer of x on X "x@X", plus the answer of y on Y "y@Y", plus the number of nodes in Y "#(Y)". The last part "#(Y)" is specifically because for any node z in Y, dist(x, z) = dist(y, z) + 1.

By similar reasoning, the answer for y in the entire tree is ans[y] = x@X + y@Y + #(X). Hence, for neighboring nodes x and y, ans[x] - ans[y] = #(Y) - #(X).

Algorithm

![image](https://user-images.githubusercontent.com/75989468/177782433-79055ca1-ce13-4e48-8087-c0cf640a0234.png)


![image](https://user-images.githubusercontent.com/75989468/177782542-9bed1d26-5873-4c3d-8a6c-36b1bce538fc.png)

Using a second, pre-order traversal, we can update our answer in linear time for all of our nodes.
