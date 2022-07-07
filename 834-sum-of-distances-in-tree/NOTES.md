Approach: Subtree Sum and Count
Intuition

Let ans be the returned answer, so that in particular ans[x] be the answer for node x.

Naively, finding each ans[x] would take O(N)O(N) time (where NN is the number of nodes in the graph), which is too slow. This is the motivation to find out how ans[x] and ans[y] are related, so that we cut down on repeated work.

Let's investigate the answers of neighboring nodes xx and yy. In particular, say xyxy is an edge of the graph, that if cut would form two trees XX (containing xx) and YY (containing yy).

Tree diagram illustrating recurrence for ans[child]
Then, as illustrated in the diagram, the answer for xx in the entire tree, is the answer of xx on XX "x@X", plus the answer of yy on YY "y@Y", plus the number of nodes in YY "#(Y)". The last part "#(Y)" is specifically because for any node z in Y, dist(x, z) = dist(y, z) + 1.

By similar reasoning, the answer for yy in the entire tree is ans[y] = x@X + y@Y + #(X). Hence, for neighboring nodes xx and yy, ans[x] - ans[y] = #(Y) - #(X).

Algorithm

Root the tree. For each node, consider the subtree SnodeS 
node
​
  of that node plus all descendants. Let count[node] be the number of nodes in SnodeS 
node
​
 , and stsum[node] ("subtree sum") be the sum of the distances from node to the nodes in SnodeS 
node
​
 .

We can calculate count and stsum using a post-order traversal, where on exiting some node, the count and stsum of all descendants of this node is correct, and we now calculate count[node] += count[child] and stsum[node] += stsum[child] + count[child].

This will give us the right answer for the root: ans[root] = stsum[root].

Now, to use the insight explained previously: if we have a node parent and it's child child, then these are neighboring nodes, and so ans[child] = ans[parent] - count[child] + (N - count[child]). This is because there are count[child] nodes that are 1 easier to get to from child than parent, and N-count[child] nodes that are 1 harder to get to from child than parent.

Tree diagram illustrating recurrence for ans[child]
Using a second, pre-order traversal, we can update our answer in linear time for all of our nodes.
