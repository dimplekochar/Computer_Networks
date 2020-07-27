#include "node.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

void routingAlgo(vector<RoutingNode*> nd){
    for (int j=0; j<nd.size(); j++){
        for (int i=0; i<nd.size(); i++){
            nd[i]->sendMsg();
        }
    }   
}


void RoutingNode::recvMsg(RouteMsg *msg) {
    for (int j = 0; j < msg->mytbl->tbl.size(); ++j){
        RoutingEntry a;
        a.ip_interface=msg->recvip;
        a.dstip=msg->mytbl->tbl[j].dstip;
        a.nexthop=msg->from;
        a.cost=1+msg->mytbl->tbl[j].cost;
        bool dup=false;
        for(int i=0; i<mytbl.tbl.size(); i++){
            if (mytbl.tbl[i].dstip==a.dstip) {
                if (mytbl.tbl[i].cost>a.cost) {
                    mytbl.tbl[i].cost=a.cost; mytbl.tbl[i].nexthop=a.nexthop; 
                }
            dup=true;
        }
    }
    if (dup==false) mytbl.tbl.push_back(a);
    };
 }





/*#include "node.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

void routingAlgo(vector<RoutingNode*> nd){
    
    for(int i=0; i<3; i++) nd[i]->sendMsg();
    
}


void RoutingNode::recvMsg(RouteMsg *msg) {
    int V = 3;
    int E = msg->mytbl->tbl.size();
    map <string, int> dist;
 
    for(int k=0; k<1; k++){
        for(int j=0; j<1; j++){
            RoutingEntry a;
            a.ip_interface=msg->mytbl->tbl[j].ip_interface;
            a.dstip=msg->mytbl->tbl[j].dstip;
            a.nexthop=msg->mytbl->tbl[j].dstip;
            
            a.cost=1;
            mytbl.tbl.push_back(a);
        
        
    for (int i = 0; i < V; i++)
        dist[msg->mytbl->tbl[i].dstip]   = 100000;
    dist[msg->recvip] = 0;
 string u, v;
         u = msg->mytbl->tbl[j].ip_interface;
            v = msg->mytbl->tbl[j].dstip;
            int weight = msg->mytbl->tbl[j].cost;
            if (dist[u] != 100000 && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        
    RoutingEntry b;
            b.ip_interface=u;
            b.dstip=v;
            b.nexthop=v;
            
            b.cost=dist[v];
            mytbl.tbl.push_back(b);
}}

    }

   */