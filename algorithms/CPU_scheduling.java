//Java program to find turn around time, waiting time for FCFS, SJF (with & without preemption), Priority (with & without preemption) CPU scheduling algorithms
/*
 * It takes no of preocesses & their priority from user
 * then generates random arrival time nd CPU burst time.
 * then each of the functions below implements different CPU scheduling algorithms and then inaaly prints the data in tabular form with all values.
 */

import java.io.*;
import java.util.*;


public class CPU_scheduling {
    
    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of Processes: ");        //taking input from user for number of processes
        int no_of_processes = in.nextInt();
        System.out.println();
        System.out.println("Enter the priority (1 being the highest): ");
        int[] priority = new int[no_of_processes];
        int temp = 0;
        for(int i = 0; i < no_of_processes; i++){
            System.out.print("Enter priority" +(i+1)+ ": ");
            temp = in.nextInt();
            priority[temp - 1] = i;
        }
            
        
        CPU_scheduling solve = new CPU_scheduling();

        int[] arrival_time = new int[no_of_processes];
        int[] burst_time = new int[no_of_processes];

        solve.assign_random_arrival_time(arrival_time, no_of_processes);        //randomly generating arrival time for each processes
        solve.assign_random_burst_time(burst_time, no_of_processes);            //randomly generating burst time for each processes between (0-29)
        System.out.println("FCFS scheduling");
        solve.fcfs(arrival_time, burst_time, no_of_processes);                  //executing the FCFS CPU scheduling algorithm

        System.out.println("SJF - Non Premptive scheduling");                   //executing the SJF- non premptive CPU scheduling algorithm
        solve.sjf_np(arrival_time, burst_time, no_of_processes);

        System.out.println("SJF - Premptive scheduling");                        //executing the SJF premptive CPU scheduling algorithm
        solve.sjf_p(arrival_time, burst_time, no_of_processes);

        System.out.println("priority - Non-Premptive scheduling");                 //executing the priority scheduling non-preemptive CPU scheduling algorithm
        solve.priority_scheduling_np(arrival_time, burst_time, no_of_processes, priority);

        System.out.println("priority - Premptive scheduling");                  //executing the priority scheduling preemptive CPU scheduling algorithm
        solve.priority_scheduling_p(arrival_time, burst_time, no_of_processes, priority);





    }

    void assign_random_arrival_time(int arrival_time[], int process_count){
        int i, index;
        Random rand = new Random();
        index = rand.nextInt(process_count);
        arrival_time[index] = 0;        //randomly choosing initial process with arrival time = 0
        for(i = 0; i < process_count; i++){
            if(i == index)
                continue;
            arrival_time[i] = rand.nextInt(50);
        }
        
    }

    void assign_random_burst_time(int burst_time[], int process_count){
        int i;
        Random rand = new Random();
        for(i = 0; i < process_count; i++){
            burst_time[i] = rand.nextInt(30);
        }
        
    }
    //first come first serve CPU scheduling algorithm
    //at = is for arrival time, bt= burst time, pc= number of processes (process count)
    void fcfs(int at[], int bt[], int pc){
        int i, j, k = 0, min, head = 0;

        //ready_queue keeps the index of processes in decresing order .i.e first in the queue in on last position on ready_queue
        int[] ready_queue = new int[pc];
        int[] array= new int[pc];
        array = at.clone();
        
        //this is for entering order of process based on their arrival time in ready_queue
        for(i = pc - 1; i >= 0; i--){
            min = array[i];
            for(j = 0; j < pc; j++){
                if(array[j] <= min)
                {
                    min = array[j];
                    k = j;
                }    
            }
            array[k] = 99;
            ready_queue[i] = k;
        }
        
        int[] completion_time = new int[pc];
        int[] waiting_time = new int[pc];
        int[] turn_around_time = new int[pc];
        

        //calculating completion time for first process in queue
        completion_time[ready_queue[pc - 1]] = bt[ready_queue[pc - 1]];
        //calculating completion time for all process
        for(i = pc - 2; i >= 0; i--){
            head = ready_queue[i];
            //if completion time of one process is less then the arrival time of succeding process example P1(arrival time, burst time)=(0, 2) and P2(arrival time, burst time)=(5, 9) then CPU is free for 3 milliseconds
            if(completion_time[ready_queue[i + 1]] < at[head])
                completion_time[head] = at[head] + bt[head];
            else
                completion_time[head] = completion_time[ready_queue[i + 1]] + bt[head];
            
        }
        //calculating turn_arounf_time and waiting time
        for(i = 0; i < pc; i++){
            turn_around_time[i] = completion_time[i] - at[i];
            waiting_time[i] = turn_around_time[i] - bt[i];
        }

        print_data(at, bt, turn_around_time, completion_time, waiting_time, ready_queue, pc);
        print_gnatt_chart(turn_around_time, completion_time, ready_queue, pc);
        
        
    }
    //shortest job first non premptive cpu scheduling
    //at = is for arrival time, bt= burst time, pc= number of processes (process count)
    void sjf_np(int at[], int bt[], int pc){
        int i, j, k = 0, min, head = 0;

        //ready_queue keeps the index of processes in decresing order
        int[] ready_queue = new int[pc];
        int[] array= new int[pc];
        array = bt.clone();
        
        //this is for entering order of process based on their burst time in ready_queue and arrival time in case of same burst time
        for(i = pc - 1; i >= 0; i--){
            min = array[i];
            for(j = 0; j < pc; j++){
                if(array[j] < min)
                {
                    min = array[j];
                    k = j;
                }
                else if(array[j] == min){
                    if(at[j] < at[k]){
                        min = array[j];
                        k = j;
                    }
                }    
            }
            array[k] = 99;
            ready_queue[i] = k;
        }
        
        int[] completion_time = new int[pc];
        int[] waiting_time = new int[pc];
        int[] turn_around_time = new int[pc];
        

        //calculating completion time for first process in queue
        completion_time[ready_queue[pc - 1]] = bt[ready_queue[pc - 1]] + at[ready_queue[pc - 1]];
        //calculating completion time for all process
        for(i = pc - 2; i >= 0; i--){
            head = ready_queue[i];
            //if completion time of one process is less then the arrival time of succeding process example P1(arrival time, burst time)=(0, 2) and P2(arrival time, burst time)=(5, 9) then CPU is free for 3 milliseconds
            if(completion_time[ready_queue[i + 1]] < at[head])
                completion_time[head] = at[head] + bt[head];
            else
                completion_time[head] = completion_time[ready_queue[i + 1]] + bt[head];
            
        }
        //calculating turn_arounf_time and waiting time
        for(i = 0; i < pc; i++){
            turn_around_time[i] = completion_time[i] - at[i];
            waiting_time[i] = turn_around_time[i] - bt[i];
        }

        print_data(at, bt, turn_around_time, completion_time, waiting_time, ready_queue, pc);
        print_gnatt_chart(turn_around_time, completion_time, ready_queue, pc);
        
        
    }
    //shortest job first premptive cpu scheduling
    void sjf_p(int at[], int bt[], int pc){

        int[] remaining_time = new int[pc];
        int[] waiting_time = new int[pc];
        int[] completion_time = new int[pc];
        int[] turn_around_time = new int[pc];
        int[] ready_queue = new int[pc];

        // Copy the burst time into remaining_time[]
        remaining_time = bt.clone();
        int j, i;
        int no_of_p_complete = 0, t = 0, min_burst_time = 99, shortest = 0;
        boolean check = false;
        
        for(i = 0; i < pc; i++)
            ready_queue[i] = pc - 1 - i;
        //iterate untill all processes are completed
        while (no_of_p_complete != pc) {
    
            // Finding process with minimum remaining burst time among the processes that has arrived till the current time
            for (j = 0; j < pc; j++) {
                if ((at[j] <= t) && (remaining_time[j] < min_burst_time) && remaining_time[j] > 0){
                    min_burst_time = remaining_time[j];
                    shortest = j;
                    check = true;
                }
            }
            
            //check is to check whether their has been any preemptive
            if (check == false) {
                t++;
                continue;
            }
 
            // Reduce remaining time by one
            remaining_time[shortest]--;
 
 
            // If a process gets completely executed
            if (remaining_time[shortest] == 0) {
                min_burst_time = 99;
                //one more process completed
                no_of_p_complete++;
                check = false;
    
                completion_time[shortest] = t + 1;
    
                // Calculating waiting time for the completed process
                waiting_time[shortest] = completion_time[shortest] - bt[shortest] - at[shortest];
                
                //for the corner case
                if (waiting_time[shortest] < 0)
                    waiting_time[shortest] = 0;

            }
            // Increment time
            t++;
        }

            // calculating turnaround time
        for (i = 0; i < pc; i++)
        turn_around_time[i] = bt[i] + waiting_time[i];

        print_data(at, bt, turn_around_time, completion_time, waiting_time, ready_queue, pc);
        
    }
    //priority scheduling algorithm
       //at = is for arrival time, bt= burst time, pc= number of processes (process count)
    void priority_scheduling_np(int at[], int bt[], int pc, int priority[]){
        int i, j, temp = 0;

        //ready_queue keeps the index of processes in decresing order .i.e first in the queue in on last position on ready_queue
        int[] process_id = new int[pc];
        
        for(i = 0; i < pc; i++){
            process_id[i] = i;
        }
        //this is for entering order of process based on their arrival time and priority in ready_queue
        for(i = 0; i < pc; i++){
            
            for(j = 0; j < pc -i -1; j++){
                if(at[j] > at[j + 1])
                {
                    temp = at[j];
                    at[j] = at[j + 1];
                    at[j + 1] = temp;

                    temp = bt[j];
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;

                    temp = process_id[j];
                    process_id[j] = process_id[j + 1];
                    process_id[j + 1] = temp;

                    temp = priority[j];
                    priority[j] = priority[j + 1];
                    priority[j + 1] = temp;
                }
                else if(at[j] == at[j + 1]){
                    if(priority[j] > priority[j + 1]){
                        temp = at[j];
                        at[j] = at[j + 1];
                        at[j + 1] = temp;

                        temp = bt[j];
                        bt[j] = bt[j + 1];
                        bt[j + 1] = temp;

                        temp = process_id[j];
                        process_id[j] = process_id[j + 1];
                        process_id[j + 1] = temp;

                        temp = priority[j];
                        priority[j] = priority[j + 1];
                        priority[j + 1] = temp;
                    }
                    
                }    
            }
            
        }
        
        int[] completion_time = new int[pc];
        int[] waiting_time = new int[pc];
        int[] turn_around_time = new int[pc];
        

        //calculating completion time for first process in queue
        completion_time[0] = at[0] + bt[0];
        turn_around_time[0] = completion_time[0] - at[0];
        waiting_time[0] = turn_around_time[0] - bt[0];
        //calculating completion time, waiting time, turn around time for all process
        for(i = 1; i < pc; i++){
            if(completion_time[i - 1] < at[i])
                completion_time[i] = at[i] + bt[i];
            else
                completion_time[i] = completion_time[i - 1] + bt[i];
            turn_around_time[i] = completion_time[i] - at[i];
            waiting_time[i] = turn_around_time[i] - bt[i];
            
        }

        print_data_for_priorty(at, bt, turn_around_time, completion_time, waiting_time, process_id, priority, pc);
        print_gnatt_chart_for_priority(turn_around_time, completion_time, process_id, pc);
        
        
    }
    //priority scheduling algorithm
    void priority_scheduling_p(int at[], int bt[], int pc, int priority[]){

        int[] remaining_time = new int[pc];
        int[] waiting_time = new int[pc];
        int[] completion_time = new int[pc];
        int[] turn_around_time = new int[pc];
        int[] ready_queue = new int[pc];

        // Copy the burst time into remaining_time[]
        remaining_time = bt.clone();
        int j, i;
        int no_of_p_complete = 0, t = 0, current_priority = 99, current_process_id = 0;
        boolean check = false;

        //this only holds the process id
        for(i = 0; i < pc; i++)
            ready_queue[i] = i;
        //iterate untill all processes are completed
        while (no_of_p_complete != pc) {
    
            // Finding process with highest priority among the processes that has arrived till the current time
            for (j = 0; j < pc; j++) {
                if ((at[j] <= t) && (priority[j] < current_priority) && remaining_time[j] > 0){
                    current_priority = priority[j];
                    current_process_id = j;
                    check = true;
                }
            }
            
            //check is see if there as been any premtive or not
            if (check == false) {
                t++;
                continue;
            }
 
            // Reduce remaining burst time by one for current running process
            remaining_time[current_process_id]--;
 
 
            // If a process gets completely executed
            if (remaining_time[current_process_id] == 0) {
                current_priority = 99;
                //one more process completed
                no_of_p_complete++;
                check = false;
                //calculating completion time for completed process
                completion_time[current_process_id] = t + 1;
    
                // Calculating waiting time for the completed process
                waiting_time[current_process_id] = completion_time[current_process_id] - bt[current_process_id] - at[current_process_id];
    
                if (waiting_time[current_process_id] < 0)
                    waiting_time[current_process_id] = 0;

            }
            // Increment time
            t++;
        }

            // calculating turnaround time
        for (i = 0; i < pc; i++)
            turn_around_time[i] = bt[i] + waiting_time[i];

        print_data_for_priorty(at, bt, turn_around_time, completion_time, waiting_time, ready_queue, priority, pc);
    }

    //this whole block of code is not part of the scheduling process its just for better representation of output
    void print_data(int at[], int bt[], int turn_around_time[], int completion_time[], int waiting_time[], int ready_queue[], int pc){
        int i, j;
        int average_turn_around_time = 0;
        int average_waiting_time = 0;
        System.out.println("\t\tALL TIMES ARE IN milliseconds (ms)");
        System.out.println("+---------------+---------------+---------------+-----------------+-----------------+--------------+");
        System.out.println("|  Process No.  |  Arrival Time |   Burst Time  | Completion Time | Turnaround Time | Waiting Time |");
        System.out.println("+---------------+---------------+---------------+-----------------+-----------------+--------------+");
        for(i = 0; i < pc; i++){
            j = ready_queue[pc - i - 1];
            System.out.println("|\tP" + (j+1) + "\t|\t" + at[j] + "\t|\t" + bt[j] + "\t|\t" + completion_time[j] + "\t|\t" + turn_around_time[j] + "\t|\t" + waiting_time[j] + "\t|");
            average_turn_around_time += turn_around_time[j];
            average_waiting_time += waiting_time[j];
        }
        System.out.println("+---------------+---------------+---------------+-----------------+-----------------+--------------+");
        System.out.println();
        
        //calculating average Turn around time & Waiting time
        System.out.println("Average Turn around time: " + (double)average_turn_around_time/pc + " milliseconds");
        System.out.println("Average Waiting time: " + (double)average_waiting_time/pc + " milliseconds");
        System.out.println();
    }

    void print_data_for_priorty(int at[], int bt[], int turn_around_time[], int completion_time[], int waiting_time[], int process_id[], int priority[], int pc){
        int i, j;
        int average_turn_around_time = 0;
        int average_waiting_time = 0;
        System.out.println("\t\tALL TIMES ARE IN milliseconds (ms)");
        System.out.println("+---------------+----------+---------------+---------------+-----------------+-----------------+--------------+");
        System.out.println("|  Process No.  | priority |  Arrival Time |   Burst Time  | Completion Time | Turnaround Time | Waiting Time |");
        System.out.println("+---------------+----------+---------------+---------------+-----------------+-----------------+--------------+");
        for(i = 0; i < pc; i++){
            System.out.println("|\tP" + (process_id[i]+1) + "\t|    "+ (priority[i]+1) +"     |\t" + at[i] + "    \t|\t" + bt[i] + "\t|\t" + completion_time[i] + "\t|\t" + turn_around_time[i] + "\t|\t" + waiting_time[i] + "\t|");
            average_turn_around_time += turn_around_time[i];
            average_waiting_time += waiting_time[i];
        }
        System.out.println("+---------------+----------+---------------+---------------+-----------------+-----------------+--------------+");
        System.out.println();
        
        //calculating average Turn around time & Waiting time
        System.out.println("Average Turn around time: " + (double)average_turn_around_time/pc + " milliseconds");
        System.out.println("Average Waiting time: " + (double)average_waiting_time/pc + " milliseconds");
        System.out.println();
        System.out.println();
        System.out.println();
    }

    //this whole block of code is not part of the scheduling process its just for better representation of gnatt chart
    void print_gnatt_chart(int turn_around_time[], int completion_time[], int ready_queue[], int pc){
        int i, j;
        System.out.println("GNATT CHART");
        
        for(i = 0; i < pc; i++){
            for(j = 1; j <= (turn_around_time[ready_queue[pc - i - 1]]/3) + 2; j++)
                System.out.print("_");
            
        }
        System.out.println();
        for(i = 0; i < pc; i++){
            System.out.print("|");
            for(j = 1; j <= (turn_around_time[ready_queue[pc - i - 1]]-2)/6; j++)
                System.out.print("_");
            System.out.print("P" + (ready_queue[pc - i - 1]+1));
            for(j = 1; j <= (turn_around_time[ready_queue[pc - i - 1]]-2)/6; j++)
                System.out.print("_");
        }
        
        System.out.println("|");
        System.out.print("0");
        for(i = 0; i < pc; i++){
            for(j = 1; j <= turn_around_time[ready_queue[pc - i - 1]]/3; j++)
                System.out.print(" ");
            System.out.print(completion_time[ready_queue[pc - i - 1]]);
        }
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println();
    }

    void print_gnatt_chart_for_priority(int turn_around_time[], int completion_time[], int process_id[], int pc){
        int i, j;
        System.out.println("GNATT CHART");
        
        for(i = 0; i < pc; i++){
            for(j = 1; j <= (turn_around_time[i]/3) + 2; j++)
                System.out.print("_");
            
        }
        System.out.println();
        for(i = 0; i < pc; i++){
            System.out.print("|");
            for(j = 1; j <= (turn_around_time[i]-2)/6; j++)
                System.out.print("_");
            System.out.print("P" + (process_id[i]+1));
            for(j = 1; j <= (turn_around_time[i]-2)/6; j++)
                System.out.print("_");
        }
        
        System.out.println("|");
        System.out.print("0");
        for(i = 0; i < pc; i++){
            for(j = 1; j <= turn_around_time[i]/3; j++)
                System.out.print(" ");
            System.out.print(completion_time[i]);
        }
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println();
    }

}
