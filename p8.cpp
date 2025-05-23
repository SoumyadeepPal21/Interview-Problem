Question was an easy / medium one from LC.

Given a string with any format containing only english letters, replace every percent - sign - sorrounded word ( % EXAMPLE % ) with the corresponding variable given inside a dictionary passed as an argument. Example:

input = "home/usr/lib/%EXAMPLE%", {EXAMPLE: "testfile.tx"}
        output =  "home/usr/lib/testfile.txt"

                  input = "Hi %USER% how are you doing today %DATE%?", {USER: "John", DATE: "01/01/2024"}
                          output =  "Hi John how are you doing today 01/01/2024?"
                                    My response was a simple algorithm that goes through every letter and whenever I see % I would call another function to get the closing sign. If no closing sign was found or no variable was mapped to that variable name, I would return error

                                            Follow Up Question:

                                            Imagine your dictionary with variables had nested variables. For example:

                                            input = "Hi %USER%", {USER: "%PRONOUN% John", PRONOUN: "Mr."}
                                                    My answer was call recursively the original function to get the final string. Interviewer said it was fine but another way was to flatten the variable dictionary before getting to change the original string.

                                                    Still missing 2 more coding interviews and 1 behavioral, wish me luck!