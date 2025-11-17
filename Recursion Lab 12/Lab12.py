array=[ 1,
        2,
        3,
        [4, 5, 6],
        7,
        [8,
          [9, 10, 11,
            [12, 13, 14]
          ]
        ],
        [15, 16, 17, 18, 19,
          [20, 21, 22,
            [23, 24, 25,
              [26, 27, 29]
            ], 30, 31
          ], 32
        ], 33
      ]

def recursive_function(main_array, index):

    if index >= len(main_array): # Have we reached the end of the current array?
        return

    var_type = type(main_array[index])
    if var_type == int: # Are we on an int?
        # We are, so print the contents
        print(main_array[index])
        recursive_function(main_array, index + 1)
    elif var_type == list: # Are we on a list?
        # In a sub-array, so get the sub-array
        sub_array = main_array[index]
        recursive_function(sub_array, 0) # Print what is in the sub-array

        recursive_function(main_array, index + 1) # Done printing the numbers in the sub-array, so go back to the main array

recursive_function(array, 0)