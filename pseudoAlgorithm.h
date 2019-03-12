//Time slots. One entry = one hour in one classroom
vector<list>Course*>>_slots;

//Table for chromosome used to determine first available slot
//Will need to use a hash_map
hash_map<CourseClass*, int> _classes;


//Fitness value for chromosome
//Will need to use a flag?
float _fitness;




//Chromosome param
//No of crossovers of parents class tables
int _numberOfCrossoverPts;

//Number of classes moved by random mutation
int _mutationSize;

//Probabillity of crossover success
int _crossoverProbability;

//Probabillity of mutation success
int _mutatinProbability;


//Mutation
void Mutation(); 
/* Takes random class and moves to another random slot.
Number of classes which will be moved is defined by the mutation size in the chromosome param */


// Genetic algorithm
class Algorithm
{

private:

    // Population of chromosomes
    vector<Schedule*> _chromosomes;

    // Inidicates wheahter chromosome belongs to best group
    vector<bool> _bestFlags;

    // Indices of best chromosomes
    vector<int> _bestChromosomes;

    // Number of best chromosomes currently saved in best group
    int _currentBestSize;

    // Number of chromosomes which are replaced in each gen offspring
    int _replaceByGeneration;

    // Pointer to algorithm observer
    ScheduleObserver* _observer;

    // Prototype of chromosomes in population
    Schedule* _prototype;

    // Current gen
    int _currentGeneration;

    // State of execution of algorithm
    AlgorithmState _state;

    // Synchronization of algorithm's state
    CCriticalSection _stateSect;

    // Pointer to global instance of algorithm
    static Algorithm* _instance;

    // Synchronization of creation and destruction. Global instance?
    static CCriticalSection _instanceSect;

public:

    // Returns reference to global instance of algorithm
    static Algorithm& GetInstance();

    // Frees memory used by gloval instance
    static void FreeInstance();

    // Initializes genetic algorithm
    Algorithm(int numberOfChromosomes,
        int replaceByGeneration,
        int trackBest,
        Schedule* prototype,
        ScheduleObserver* observer);

    // Frees used resources
    ~Algorithm();

    // Starts and executes algorithm
    void Start();

    // Stops execution of algoruthm
    void Stop();

    // Returns pointer to best chromosomes in pop
    Schedule* GetBestChromosome() const;

    // Returns current gen
    inline int GetCurrentGeneration() const { return _currentGeneration; }

    // Returns pointe to algorithm's observer
    inline ScheduleObserver* GetObserver() const { return _observer; }

private:

    // Tries to add chromosomes in best chromosome group
    void AddToBest(int chromosomeIndex);

    // Returns TRUE if chromosome belongs to best chromosome group
    bool IsInBest(int chromosomeIndex);

    // Clears best chromosome group
    void ClearBest();

};