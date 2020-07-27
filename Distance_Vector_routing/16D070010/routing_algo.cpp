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

void RoutingNode::recvMsg(RouteMsg *msg){
    for (int j = 0; j < msg->mytbl->tbl.size(); ++j){
        RoutingEntry a;
        a.ip_interface=msg->recvip;
        a.dstip=msg->mytbl->tbl[j].dstip;
        a.nexthop=msg->from;
        a.cost=1+msg->mytbl->tbl[j].cost;
        bool dup=false;
        for(int i=0; i<mytbl.tbl.size(); i++){
            if (mytbl.tbl[i].dstip==a.dstip){
                if (mytbl.tbl[i].cost>a.cost){
                    mytbl.tbl[i].cost=a.cost; 
                    mytbl.tbl[i].nexthop=a.nexthop;
                    mytbl.tbl[i].ip_interface=a.ip_interface;
                }
            dup=true;
        }
    }
    if (dup==false) mytbl.tbl.push_back(a);
    };
 }