#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @firts: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: return a pointer to the lowest common ancestor 
 **/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *aux = first;

    if (first == NULL || second == NULL)
        return (NULL);

    while (second != NULL)
    {
        second = second->parent;
        while (aux != NULL)
        {
            if (aux == second)
                return ((binary_tree_t *) second);
            aux = aux->parent;
        }
        aux = first;
    }
    return (NULL);
}
