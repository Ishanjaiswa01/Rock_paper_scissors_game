import schedule
import time

def study_reminder(subject, duration):
    """Displays a reminder message for the scheduled study session."""
    print(f"Time to study {subject} for {duration} minutes!")

def add_study_session(subject, time_str, duration):
    """Schedules a study session at a specified time."""
    schedule.every().day.at(time_str).do(study_reminder, subject=subject, duration=duration)
    print(f"Scheduled {subject} at {time_str} for {duration} minutes.")

def get_user_input():
    """Handles user input for scheduling study sessions."""
    while True:
        subject = input("Enter subject: ")
        time_str = input("Enter time (HH:MM in 24-hour format): ")
        duration = input("Enter duration (minutes): ")
        
        add_study_session(subject, time_str, duration)
        
        if input("Do you want to add another session? (yes/no): ").strip().lower() != 'yes':
            break

def run_scheduler():
    """Runs the scheduler to check for pending study sessions."""
    print("Study schedule set! Keep this program running to receive reminders.")
    while True:
        schedule.run_pending()
        time.sleep(30)  # Checks every 30 seconds for scheduled tasks

def main():
    """Main function to start the study planner."""
    print("Welcome to Personalized Study Planner!")
    get_user_input()
    run_scheduler()

if __name__ == "__main__":
    main()
