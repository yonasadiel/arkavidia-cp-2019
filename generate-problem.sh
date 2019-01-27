#!/bin/sh

# Usage: ./generate-problem <id> <problem-slug> <problem-name> <time-limit> <memory-limit>
# Example "problem" ./generate-problem cf-999H "Problem Name" 0.5 64

read -p 'Probid: ' PROBID
read -p 'Problem folder name: ' PROBLEM_SLUG
read -p 'Problem name: ' PROBLEM_NAME
read -p 'Time Limit: ' TIME_LIMIT
read -p 'Memory Limit: ' MEM_LIMIT

prepare_problem() {
    # Generate statement, solution, and testcases
    echo "preparing problem"
    cd "$PROBLEM_SLUG"
    pdflatex "statement.tex"
    rm *.aux *.log *.dvi *.out *.toc *.synctex.gz

    g++ solution.cpp -O2 -Wall -o solution -std=c++11
    $TCFRAME_HOME/scripts/tcframe build
    ./runner
    cd ".."
}

create_problem() {
    echo "creating problem"
    mkdir "temp"
    cd "temp"

    # Generate domjudge-problem.ini
    echo "probid=$PROBID" > domjudge-problem.ini
    echo "timelimit='$TIME_LIMIT'" >> domjudge-problem.ini

    # Generate problem.yaml
    echo "---" > problem.yaml
    echo "name: $PROBLEM_NAME" >> problem.yaml
    echo "limits:" >> problem.yaml
    echo "    memory: $MEM_LIMIT" >> problem.yaml

    # Add testcase
    mkdir "data"
    mkdir "data/secret"
    for testcases in "../$PROBLEM_SLUG/tc/*"; do
        cp $testcases "data/secret"
    done
    cd "data/secret"
    rename 's/\.out$/.ans/' *
    rename 's/^.*_//' *
    cd "../.."

    # Add statement
    cp "../$PROBLEM_SLUG/statement.pdf" "problem.pdf"

    zip -r "problem.zip" "."
    mv "problem.zip" "../$PROBLEM_SLUG/"
    cd ..
    rm -r "temp"
}

$(prepare_problem)
$(create_problem)
