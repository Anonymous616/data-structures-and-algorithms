import pandas as pd


def sjf(processes):

    p_df = pd.DataFrame(processes)

    # Sort according to arrival and burst
    p_df = p_df.sort_values(by=['Arrival', 'Burst'], ascending=True)
    p_df.reset_index(inplace=True)
    print(p_df)

    prev = 0
    # Initialize Burst
    ct = [float(p_df['Arrival'][0]) + float(p_df['Burst'][0])]
    tt = [ct[0] - float(p_df['Arrival'][0])]  # Initialize TAT
    wt = [0]  # Initialize Waiting

    for index, row in p_df[1:].iterrows():
        ct.append(float(row['Burst'] + ct[index - 1]))
        tt.append(ct[index] - row['Arrival'])
        wt.append(tt[index] - row['Burst'])

        print("Completion Time : ", ct)
        print("Waiting Time : ", wt)
        print("Turnaround Time : ", tt)
        print()

    print("Sum Waiting Time : ", sum(wt))
    print("Sum Turnaround Time : ", sum(tt))
    print("Average Waiting Time : ", sum(wt)/len(processes))
    print("Average Turnaround Time : ", sum(tt)/len(processes))

# n = int(input("Enter no of processes : "))
# processes = []
# bt = []
# at = []
# for i in range(n):
#     processes.append(
#             {
#                 "ID" : int(input("Enter process id: ")),
#                 "Arrival" : float(input("Enter arrival time: ")),
#                 "Burst"  : float(input("Enter burst time: "))
#             }
#         )


sjf(
    [
        {"Id": 2, "Arrival": 2, "Burst": 4, },
        {"Id": 0, "Arrival": 1, "Burst": 2, },
        {"Id": 1, "Arrival": 1, "Burst": 6, },
        {"Id": 3, "Arrival": 3, "Burst": 9, },
        {"Id": 4, "Arrival": 4, "Burst": 12}
    ]
)

# sjf(processes)
