#ifndef TASKS_H_
#define TASKS_H_

typedef enum {
    LOW, MEDIUM, HIGH
} Priority;

typedef unsigned int task_id_t;

typedef struct {
    task_id_t id;
    Priority priority;
} Task;

/**
 * Zwróć uchwyt "tylko do odczytu" do zadania o wyższym priorytecie.
 *
 * @param t1 wskaźnik do zadania #1
 * @param t2 wskaźnik zadania #2
 * @return wskaźnik do zadania o wyższym priorytecie (t1 albo t2)
 */
const Task* choose_more_important_task(const Task* t1, const Task* t2);

/**
 * Zwróć tekstową reprezentację priorytetu.
 *
 * @param p priorytet
 * @return tekstowa reprezentację priorytetu [łańcuch znaków]
 */
const char* priority_as_str(Priority p);

/**
 * Zwiększ priorytet o jeden stopień (chyba, że priorytet jest już najwyższy z możliwych).
 *
 * @param p wskaźnik do priorytetu (tj. wskaźnik na typ Priority)
 */
void increase_priority(Priority* p);

/**
 * Dokonaj transformacji zadania.
 *
 * Transformacja polega na dwukrotnym wywołaniu funkcji wskazywanej przez `f`,
 * przekazanej jako argument wywołania transform_task(), każdorazowo podając
 * uchwyt do priorytetu zadania `t` jako argument funkcji wskazywanej przez `f`.
 *
 * @param t wskaźnik do zadania
 * @param f wskaźnik do funkcji przyjmującej "zwykły" wskaźnik na typ Priority
 *   (funkcja ta nie zwraca żadnej wartości)
 */
void transform_task(Task* t, void(* f)(Priority*));

#endif /* TASKS_H_ */
