class Vertex:
    def __init__(self, node: str):
        self.id = node
        self.adjacent = {}
        self.distance = float('inf')
        self.visited = False
        self.previous = None

    def add_neighbour(self, neighbour, weight=0):
        self.adjacent[neighbour] = weight

    def get_connections(self):
        return self.adjacent.keys()

    def get_vertex_ID(self):
        return self.id

    def get_weight(self, neighbour):
        return self.adjacent[neighbour]

    def set_distance(self, dist):
        self.distance = dist

    def get_distance(self):
        return self.distance

    def set_previous(self, prev):
        self.previous = prev

    def set_visited(self):
        self.visited = True

    def __str__(self):
        return str(self.id) + 'adjacent: ' + str([x.id for x in self.adjacent])

    def __lt__(self, other):
        return self.distance < other.distance

    def __le__(self, other):
        return self.distance <= other.distance

    def __gt__(self, other):
        return self.distance > other.distance

    def __ge__(self, other):
        return self.distance >= other.distance

    def __eq__(self, other):
        return self.distance == other.distance

    def __hash__(self):
        return hash(self.id)


class Graph:
    def __init__(self):
        self.vertices = {}
        self.n_vertices = 0

    def __iter__(self):
        return iter(self.vertices.values())

    def add_vertex(self, node):
        self.n_vertices += 1
        new_vrtx = Vertex(node)
        self.vertices[node] = new_vrtx
        return new_vrtx

    def get_vertex(self, n):
        if n in self.vertices:
            return self.vertices[n]
        else:
            return None

    def add_edge(self, frm, to, cost=0):
        if frm not in self.vertices:
            self.add_vertex(frm)
        if to not in self.vertices:
            self.add_vertex(to)
        self.vertices[frm].add_neighbour(self.vertices[to], cost)
        self.vertices[to].add_neighbour(self.vertices[frm], cost)

    def get_vertices(self):
        return self.vertices.keys()

    def get_edges(self):
        edges = []
        for v in self:
            for w in v.get_connections():
                vid = v.get_vertex_ID()
                wid = w.get_vertex_ID()
                edges.append((vid, wid, v.get_weight(w)))
        return edges


if __name__ == '__main__':
    g = Graph()
    for i in 'abcde':
        g.add_vertex(i)
    for v, w, c in zip('aacbcd', 'bcbede', [4, 1, 2, 4, 4, 4]):
        g.add_edge(v, w, c)
    print(g.get_edges())
