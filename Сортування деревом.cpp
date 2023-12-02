#include <iostream>

using namespace std;

// Структура - вузол дерева

struct tnode
{
    int field; // поле даних

    struct tnode* left; // лівий нащадок

    struct tnode* right; // правий нащадок
};

// Виведення вузлів дерева

void treeprint(tnode* tree)
{
    if (tree != NULL) // поки не зустрінеться порожній вузол
    {      
        treeprint(tree->left);  // рекурсивна функція виведення лівого піддерева

        cout << tree->field << " "; // відображає корінь дерева

        treeprint(tree->right); // рекурсивна функція виведення правого піддерева
    }
}

// Додавання вузлів у дерево

struct tnode* addnode(int x, tnode* tree) 
{
    if (tree == NULL) // якщо дерева немає, то формується корінь
    {
        tree = new tnode; // пам'ять під вузол

        tree->field = x; // поле данних

        // вітки стають порожніми

        tree->left = NULL;

        tree->right = NULL; 
    }
    else
        if (x < tree->field) // якщо елемент x менше кореневого, виходимо вліво

            tree->left = addnode(x, tree->left); // рекурсивно додаємо елемент

        else

            tree->right = addnode(x, tree->right); // рекурсивно додаємо элемент

    return(tree);
}

// Звільнення пам'яті дерева

void freemem(tnode* tree)
{
    if (tree != NULL) // якщо дерево не порожнє
    {
        freemem(tree->left); // рекурсивно видаляємо ліву вітку

        freemem(tree->right); // рекурсивно видаляємо праву вітку

        delete tree; // видаляємо корінь
    }
}

// Запуск програми

int main()
{
    struct tnode* root = 0; // оголошуємо структуру дерева

    system("chcp 1251");

    system("cls");

    long a;

    for (int i = 0; i < 15; i++)
    {
        cout << "Введіть вузол " << i + 1 << ": ";

        cin >> a;

        root = addnode(a, root); // розміщуємо введений вузол на дереві
    }
    treeprint(root); // виводимо елементи дерева, отримуємо відсортований масив

    freemem(root); // видаляємо виділену пам'ять

    cin.get();  cin.get();

    return 0;
}