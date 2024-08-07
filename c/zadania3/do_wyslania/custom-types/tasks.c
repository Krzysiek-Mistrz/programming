#include "tasks.h"

const Task* choose_more_important_task(const Task* t1, const Task* t2) {
    return (t1->priority >= t2->priority) ? t1 : t2;
}

const char* priority_as_str(Priority p) {
    switch (p) {
        case LOW: return "LOW";
        case MEDIUM: return "MEDIUM";
        case HIGH: return "HIGH";
        default:
            return "unknown";
    }
}

void increase_priority(Priority* p) {
    ++(*p);
    if (*p > HIGH) {
        *p = HIGH;
    }
}

/*
 * Konieczność zastosowania pierwsza pary nawiasów (wokół `* f`) została omówiona
 *   w skrypcie w rozdz. "Definicja wskaźnika do funkcji".
 *
 * Ponieważ wskaźnik do funkcji pełni jedynie rolę uchwytu (czyli nie musi znać
 *   implementacji wskazywanej funkcji), nie ma potrzeby podawania nazw parametrów
 *   wskazywanej funkcji -- wystarczy podać typ tych parametrów (analogicznie jak
 *   w przypadku deklaracji funkcji, zob. w skrypcie rozdz. "Tworzenie funkcji",
 *   a dokładniej " Deklaracja (prototyp)").
 */
void transform_task(Task* t, void(* f)(Priority*)) {
    f(&t->priority);
    f(&t->priority);
}
