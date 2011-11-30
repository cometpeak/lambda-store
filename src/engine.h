/*
 *  Philip Shao
 *  Other includes
 *
 */

#include <map>;

class Storage {
    map<string, Node> data;  // Simple data structure.
};


void Storage::Execute(Node& node, Expr *returnValue) { 
    if (node->rootType == "update"){
        // Update
        UpdateExpr updateExpr = (UpdateExpr)node;
        UpdateExpr currentHead = storage_[updateExpr->key()];
        storage_[updateExpr->key()] = updateExpr;
        updateExpr->setExpr(currentHead);
        
    } else if (node->rootType == "read") {
        // Read
        ReadExpr readExpr = (ReadExpr)node;
        *returnValue = storage_[readExpr->key()]->recursiveEval();
        // Recursive eval implemented in the Expression class...
    }
}

