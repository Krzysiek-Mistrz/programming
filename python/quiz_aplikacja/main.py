import tkinter as tk
from tkinter import messagebox

class QuizApp:
    #default app window layout
    def __init__(self, master):
        self.master = master
        self.master.title("Quiz")
        self.master.configure(bg="#f0f0f0")  # Background color

        self.questions = self.load_questions()
        self.current_question_index = 0
        self.correct_answers = 0

        #label for our question
        self.question_label = tk.Label(master, text="", wraplength=300, bg="#f0f0f0", font=("Arial", 14), fg="#333")
        self.question_label.pack(pady=10)

        #variable for our selected answer from the user
        self.var = tk.StringVar()
        self.var.set(None)

        self.radio_buttons = []
        for i in range(4):
            #connect self.var with circ selector of radio button
            rb = tk.Radiobutton(master, text="", variable=self.var, value=i, 
                                bg="#ffffff", fg="#333", font=("Arial", 12), 
                                indicatoron=0, width=30, height=2, 
                                selectcolor="#ffffff", padx=10, pady=5, 
                                relief="flat", highlightbackground="#cccccc", 
                                highlightcolor="#cccccc", bd=2)
            rb.pack(anchor="center", pady=5)
            self.radio_buttons.append(rb)

        #after click call check_answer func
        self.submit_button = tk.Button(master, text="Submit", command=self.check_answer, bg="#4CAF50", fg="white", font=("Arial", 12))
        self.submit_button.pack(pady=20)

        self.retake_button = tk.Button(master, text="Retake Quiz", command=self.retake_quiz, bg="#FF5722", fg="white", font=("Arial", 12))
        self.retake_button.pack(pady=20)
        #hide retake button initially
        self.retake_button.pack_forget()

        self.end_button = tk.Button(master, text="End Quiz", command=self.quit_quiz, bg="#FF5722", fg="white", font=("Arial", 12))
        self.end_button.pack(pady=5)
        #hide end button initially
        self.end_button.pack_forget()

        self.load_next_question()

    def load_questions(self):
        try:
            with open("questions_anwsers.txt", "r") as file:
                lines = file.readlines()

            if len(lines) % 6 != 0:
                raise ValueError("The file format is incorrect. The total number of lines must be a multiple of 6.")

            #loading all questions to questions var
            questions = []
            for i in range(0, len(lines), 6):
                #loading questions from file
                question = {
                    "question": lines[i].strip(),
                    "options": [lines[i+1].strip(), lines[i+2].strip(), lines[i+3].strip(), lines[i+4].strip()],
                    "correct": lines[i+5].strip()
                }
                questions.append(question)
            return questions

        #there might be 2 common errors: file wont exist and num of lines in file is incorrect for the app to run
        except FileNotFoundError:
            messagebox.showerror("Error", "The question file was not found!")
            self.master.quit()
            return []

        except ValueError as ve:
            messagebox.showerror("Error", str(ve))
            self.master.quit()
            return []

    #setting text of rad buttons next to select circ and question
    def load_next_question(self):
        if self.current_question_index < len(self.questions):
            #setting text of question
            question = self.questions[self.current_question_index]
            self.question_label.config(text=question["question"])
            #setting the options (text) of anwsers in window next to circ selector
            for i, option in enumerate(question["options"]):
                self.radio_buttons[i].config(text=option, value=chr(65+i))
                #reset the current anwser
            self.var.set(None)
        else:
            self.end_quiz()

    def check_answer(self):
        #reading the input from selected anwser
        selected_answer = self.var.get()
        #retrieving value from list[dict[key]]
        correct_answer = self.questions[self.current_question_index]["correct"]

        if selected_answer == correct_answer:
            self.correct_answers += 1

        self.current_question_index += 1
        self.load_next_question()

    def end_quiz(self):
        #disable submit button
        self.submit_button.config(state="disabled")
        messagebox.showinfo("Quiz Finished", f"Your score: {self.correct_answers}/{len(self.questions)}")
        #show retake button
        self.retake_button.pack()
        self.end_button.pack()

    def retake_quiz(self):
        self.current_question_index = 0
        self.correct_answers = 0
        self.retake_button.pack_forget()  # Hide retake button
        self.load_next_question()
        self.submit_button.config(state="normal")  # Enable submit button
        
    def quit_quiz(self):
        self.master.quit()

if __name__ == "__main__":
    root = tk.Tk()
    #giving the window object as init
    quiz_app = QuizApp(root)
    #run mainloop which waits for user interraction
    root.mainloop()
