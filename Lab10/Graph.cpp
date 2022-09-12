#include "Graph.h"
#include <iostream>
/*
Graph::Graph(ifstream &in)
{
    int a = 0;
    int b = 0;
    in >> a;
    in >> b;
    string s;
    int pos1 = 0;
    int pos2 = 0;
    for (int i = 0; i < a; i++)
    {
        in >> s;
        Vertex v;
        v.label = s;
        vertices.push_back(v);
    }
    for (int i = 0; i < b; b--)
    {
        in >> s;
        pos1 = find(s);
        in >> s;
        pos2 = find(s);
        int num = 0;
        in >> num;
        pair<int, int> p(pos2, num);
        vertices.at(pos1).neighbors.push_back(p);
    }
}

void Graph::output_graph(const string &s)
{
    ofstream out(s.c_str());
    if (!out.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    out << "digraph G {" << endl;
    output_graph(out);
    out << "}";
    out.close();

    string jpegFileName = s.substr(0, s.size() - 4) + ".jpg";
    string command = "dot -Tjpg " + s + " -o " + jpegFileName;
    system(command.c_str());
}

void Graph::output_graph(ofstream &s)
{
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        s << vertices.at(i).label << " [label=\"" << vertices.at(i).label << ", distance = " << vertices.at(i).distance << "\"];" << endl;
        cout << vertices.at(i).distance << endl;
        Vertex v = vertices.at(i);
        for (list<pair<int, int> >::iterator curr = v.neighbors.begin(); curr != v.neighbors.end(); curr++)
        {
            int initial = i;
            int final = curr->first;
            s << vertices.at(initial).label << " -> " << vertices.at(final).label << ";" << endl;
        }
    }
}

void Graph::bfs()
{
    queue<Vertex> a;
    vertices.at(0).color = "GREY";
    vertices.at(0).distance = 0;
    a.push(vertices.at(0));
    while (!a.empty())
    {
        Vertex v = a.front();
        a.pop();
        for (list<pair<int, int> >::iterator curr = v.neighbors.begin(); curr != v.neighbors.end(); curr++)
        {
            int here = curr->first;
            if (vertices.at(here).color == "WHITE")
            {
                vertices.at(here).color = "GREY";
                vertices.at(here).distance = v.distance + 1;
                cout << vertices.at(here).distance << endl;
                vertices.at(here).prev = &v;
                a.push(vertices.at(here));
            }
            v.color = "BLACK";
        }

        for (unsigned i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).color == "WHITE")
                vertices.at(i).distance = INT_MAX;
        }
    }
}

int Graph::find(string s)
{
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).label == s)
            return i;
    }
    return -1;
}

void Graph::search(Vertex &v)
{
    v.color = "GRAY";
    cout << v.label << ", ";
    for (list<pair<int, int> >::iterator curr = v.neighbors.begin(); curr != v.neighbors.end(); curr++)
    {
        if (vertices.at(curr->first).color == "WHITE")
        {
            vertices.at(curr->first).prev = &v;
            vertices.at(curr->first).distance = v.distance + 1;
            search(vertices.at(curr->first));
        }
        v.color = "BLACK";
    }
}

void Graph::dfs()
{
    vertices.at(0).distance = 0;
    for (unsigned i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).color == "WHITE")
            search(vertices.at(i));
    }
}*/