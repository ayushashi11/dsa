from classes import Graph, Vertex
import heapq
from typing import *


def dijkstra(G: Graph, source: Vertex):
    source.set_distance(0)
    unvisitedQueue: list = [v for v in G]
    heapq.heapify(unvisitedQueue)
    while len(unvisitedQueue):
        current: Vertex = heapq.heappop(unvisitedQueue)
        current.set_visited()
        for nex in current.adjacent:
            if nex.visited:
                continue
            newDist = current.get_distance() + current.get_weight(nex)
            if newDist < nex.get_distance():
                nex.set_distance(newDist)
                nex.set_previous(current)
                print(
                    f"Updated: current={current.get_vertex_ID()},"
                    f"next={nex.get_vertex_ID()},"
                    f"newDist={newDist}"
                    )
        while len(unvisitedQueue):
            heapq.heappop(unvisitedQueue)
        unvisitedQueue: list = [
            v for v in G if not v.visited
            ]
        heapq.heapify(unvisitedQueue)


if __name__ == '__main__':
    g = Graph()
    for i in 'abcde':
        g.add_vertex(i)
    for v, w, c in zip('aacbcd', 'bcbede', [4, 1, 2, 4, 4, 4]):
        g.add_edge(v, w, c)
    print(g.get_edges())
    dijkstra(g, g.get_vertex('a'))
