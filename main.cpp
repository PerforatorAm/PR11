#include <iostream>
#include <string>
using namespace std;

struct a {
    string b;
    string c;
    int d;
};

struct e {
    a f;
    e* g;
};

struct h {
    e* i;
    e* j;
    int k;
};

long long l = 0;
long long m = 0;

void n(h& o) {
    o.i = nullptr;
    o.j = nullptr;
    o.k = 0;
}

e* p(a f) {
    e* q = new e;
    q->f = f;
    q->g = nullptr;
    l++;
    return q;
}

bool r(h& o) {
    return o.i == nullptr;
}

void s(h& o, a f) {
    e* q = p(f);
    if (o.i == nullptr) {
        o.i = q;
        o.j = q;
    }
    else {
        o.j->g = q;
        o.j = q;
    }
    o.k++;
}

void t(h& o, a f) {
    e* q = p(f);
    if (o.i == nullptr) {
        o.i = q;
        o.j = q;
    }
    else {
        q->g = o.i;
        o.i = q;
    }
    o.k++;
}

bool u(a v, a w) {
    return v.b == w.b && v.c == w.c && v.d == w.d;
}

bool x(h& o) {
    e* y = o.i;
    e* z = o.i;
    while (z != nullptr && z->g != nullptr) {
        y = y->g;
        z = z->g->g;
        if (y == z) {
            return true;
        }
    }
    return false;
}

bool aa(h& o) {
    if (x(o)) {
        cout << "Error: cycle detected!" << endl;
        return false;
    }

    int ab = 0;
    e* ac = o.i;
    e* ad = nullptr;

    while (ac != nullptr && ab <= o.k) {
        ad = ac;
        ac = ac->g;
        ab++;
    }

    if (ab != o.k) {
        cout << "Error: incorrect size!" << endl;
        return false;
    }

    if (ad != o.j) {
        cout << "Error: incorrect tail!" << endl;
        return false;
    }

    if (o.j != nullptr && o.j->g != nullptr) {
        cout << "Error: tail next is not nullptr!" << endl;
        return false;
    }

    cout << "Structure check: OK" << endl;
    return true;
}

void ae(h& o) {
    if (r(o)) {
        cout << "List is empty." << endl;
        return;
    }

    e* ac = o.i;
    int af = 1;

    while (ac != nullptr) {
        cout << af << ". "
            << ac->f.b << " | "
            << ac->f.c << " | "
            << ac->f.d << endl;
        ac = ac->g;
        af++;
    }

    cout << "Viewed nodes: " << af - 1 << endl;
}

void ag(h& o) {
    e* ac = o.i;
    int af = 1;
    cout << "ADDRESS DIAGNOSTICS" << endl;

    while (ac != nullptr) {
        cout << "Node " << af << " current: " << static_cast<void*>(ac)
            << " | next: " << static_cast<void*>(ac->g) << endl;
        ac = ac->g;
        af++;
    }

    cout << "Last node points to nullptr." << endl;
}

void ah(h& o) {
    e* ac = o.i;
    while (ac != nullptr) {
        e* ai = ac->g;
        delete ac;
        m++;
        ac = ai;
    }
    o.i = nullptr;
    o.j = nullptr;
    o.k = 0;
}

bool aj(h& o, a ak[], int al) {
    e* ac = o.i;
    for (int am = 0; am < al; am++) {
        if (ac == nullptr) return false;
        if (!u(ac->f, ak[am])) return false;
        ac = ac->g;
    }
    return ac == nullptr;
}

bool an() {
    h o;
    n(o);
    bool ao = r(o) && aa(o);
    ah(o);
    return ao;
}

bool ap() {
    h o;
    n(o);
    a aq = { "Kovalenko", "IT", 5 };
    s(o, aq);
    bool ao = o.k == 1 && o.i == o.j && u(o.i->f, aq);
    ah(o);
    return ao;
}

bool ar() {
    h o;
    n(o);
    a at = { "Kovalenko", "IT", 5 };
    a au = { "Melnyk", "HR", 3 };
    s(o, at);
    s(o, au);
    a av[] = { at, au };
    bool ao = aj(o, av, 2);
    ah(o);
    return ao;
}

bool aw() {
    h o;
    n(o);
    a at = { "Kovalenko", "IT", 5 };
    a au = { "Melnyk", "HR", 3 };
    t(o, at);
    t(o, au);
    a av[] = { au, at };
    bool ao = aj(o, av, 2);
    ah(o);
    return ao;
}

bool ax() {
    h o;
    n(o);
    a aq = { "Kovalenko", "IT", 5 };
    s(o, aq);
    s(o, aq);
    bool ao = o.k == 2 && u(o.i->f, o.j->f);
    ah(o);
    return ao;
}

bool ay() {
    h o;
    n(o);
    a aq = { "Newbie", "IT", 0 };
    s(o, aq);
    bool ao = o.i->f.d == 0;
    ah(o);
    return ao;
}

bool az() {
    h o;
    n(o);
    a aq = { "Invalid", "IT", -2 };
    s(o, aq);
    bool ao = o.i->f.d == -2;
    ah(o);
    return ao;
}

bool ba() {
    h o;
    n(o);
    for (int am = 0; am < 10; am++) {
        a aq = { "Emp", "Dept", am };
        s(o, aq);
    }
    bool ao = o.k == 10 && aa(o);
    ah(o);
    return ao;
}

bool bb() {
    h o;
    n(o);
    a aq = { "Kovalenko", "IT", 5 };
    s(o, aq);
    e* bc = o.i;
    ae(o);
    ae(o);
    bool ao = bc == o.i;
    ah(o);
    return ao;
}

bool bd() {
    h o;
    n(o);
    for (int am = 0; am < 100; am++) {
        a aq = { "Emp", "Dept", am };
        s(o, aq);
    }
    bool ao = o.k == 100;
    ah(o);
    return ao && r(o);
}

bool be() {
    h o;
    n(o);
    a aq = { "Kovalenko", "IT", 5 };
    s(o, aq);
    ah(o);
    s(o, aq);
    bool ao = o.k == 1 && u(o.i->f, aq);
    ah(o);
    return ao;
}

bool bf() {
    h o;
    n(o);
    a aq = { "Melnyk", "HR", 3 };
    s(o, aq);
    ah(o);
    s(o, aq);
    ah(o);
    return r(o);
}

bool bg() {
    h o;
    n(o);
    a at = { "Kovalenko", "IT", 5 };
    a au = { "Melnyk", "HR", 3 };
    s(o, at);
    s(o, au);
    bool ao = o.j->g == nullptr;
    ah(o);
    return ao;
}

bool bh() {
    h o;
    n(o);
    a at = { "Kovalenko", "IT", 5 };
    a au = { "Melnyk", "HR", 3 };
    s(o, at);
    s(o, au);
    bool ao = o.j->f.b == "Melnyk";
    ah(o);
    return ao;
}

bool bi() {
    h o;
    n(o);
    ah(o);
    return o.i == nullptr && o.j == nullptr && o.k == 0;
}

void bj() {
    int bk = 0;
    int bl = 15;

    cout << "\nAUTOMATED TESTS" << endl;

    if (an()) bk++;
    if (ap()) bk++;
    if (ar()) bk++;
    if (aw()) bk++;
    if (ax()) bk++;
    if (ay()) bk++;
    if (az()) bk++;
    if (ba()) bk++;
    if (bb()) bk++;
    if (bd()) bk++;
    if (be()) bk++;
    if (bf()) bk++;
    if (bg()) bk++;
    if (bh()) bk++;
    if (bi()) bk++;

    cout << "Passed: " << bk << "/" << bl << endl;
}

int main() {
    h o;
    n(o);

    int bm;
    cout << "Enter number of employees: ";
    cin >> bm;

    if (cin.fail() || bm < 0 || bm > 100) {
        cout << "Incorrect number!" << endl;
        return 1;
    }

    a bn[100];

    for (int am = 0; am < bm; am++) {
        cout << "\nEmployee " << am + 1 << endl;
        cout << "Name: ";
        cin >> bn[am].b;
        cout << "Department: ";
        cin >> bn[am].c;
        cout << "Experience: ";
        cin >> bn[am].d;

        if (cin.fail()) {
            cout << "Incorrect input!" << endl;
            ah(o);
            return 1;
        }
    }

    cout << "\nCREATION: ADD TO END" << endl;
    for (int am = 0; am < bm; am++) {
        s(o, bn[am]);
    }
    ae(o);
    aa(o);
    ag(o);

    cout << "\nCLEAR LIST" << endl;
    ah(o);
    cout << "After clear: ";
    aa(o);

    cout << "\nCREATION: ADD TO BEGINNING" << endl;
    for (int am = 0; am < bm; am++) {
        t(o, bn[am]);
    }
    ae(o);
    aa(o);
    ag(o);

    cout << "\nCLEAR LIST" << endl;
    ah(o);
    cout << "After clear: ";
    aa(o);

    bj();

    cout << "\nMEMORY REPORT" << endl;
    cout << "Allocated nodes: " << l << endl;
    cout << "Freed nodes: " << m << endl;
    cout << "Active nodes: " << l - m << endl;
    cout << "Final list state: " << (r(o) ? "empty" : "not empty") << endl;

    return 0;
}
