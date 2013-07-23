/*===========================================================================*
 * This file is part of the Abstract Library for Parallel Search (ALPS).     *
 *                                                                           *
 * ALPS is distributed under the Eclipse Public License as part of the       *
 * COIN-OR repository (http://www.coin-or.org).                              *
 *                                                                           *
 * Authors:                                                                  *
 *                                                                           *
 *          Yan Xu, Lehigh University                                        *
 *          Ted Ralphs, Lehigh University                                    *
 *                                                                           *
 * Conceptual Design:                                                        *
 *                                                                           *
 *          Yan Xu, Lehigh University                                        *
 *          Ted Ralphs, Lehigh University                                    *
 *          Laszlo Ladanyi, IBM T.J. Watson Research Center                  *
 *          Matthew Saltzman, Clemson University                             *
 *                                                                           * 
 *                                                                           *
 * Copyright (C) 2001-2013, Lehigh University, Yan Xu, and Ted Ralphs.       *
 *===========================================================================*/

#ifndef AlpsParams_h
#define AlpsParams_h

#include "AlpsKnowledge.h"
#include "AlpsParameterBase.h"

// TODO: remove largeSize, mediumSize, smallSize

//#############################################################################

//class AlpsEncoded;

//** Parameters used in Alps. */
class AlpsParams : public AlpsParameterSet {
 public:
  /** Character parameters. All of these variable are used as booleans
      (ture = 1, false = 0). */
  enum boolParams
  {
      /** Check memory.
	  Default: false */
      checkMemory,
      /** Remove dead nodes or not. 
          Default: true. */
      deleteDeadNode,
      /** Master balances the workload of hubs: centralized. 
          Default: true. */
      interClusterBalance,
      /** Hub balances the workload of workers: receiver initialized. 
          Default: true*/
      intraClusterBalance,
      /** Print solution to screen and log if have a solution and msgLevel and
          logFileLevel permits. 
          Default: false. */
      printSolution,
      /***/
      endOfBoolParams
  };

  /** Integer paramters. */
  enum intParams
  {
      /** The size of extra memory allocated to a message buffer. 
          Default: 256 byte */
      bufSpare,
      /** Type of clock when timing rampup, rampdown, etc. 
	  CPU or Wallclock. 
	  default: wallclock */
      clockType,
      /** Number of the "elite" nodes that are used in determining workload. 
          Default: 1 */
      eliteSize,
      /** The number of nodes initially generated by each hub. 
          Default: 2 */
      hubInitNodeNum,
      /** Message level of the hub specific messages. 
          (0: no print to screen; 1: summary; 2: moderate; 3: verbose) 
          Default: 0
      */
      hubMsgLevel,
      /** The number of hubs. 
          Default: 1 */
      hubNum,
      /** The size of memory allocated for large size message.
          Default: 10485760 */
      largeSize,
      /** The level of log file.
          (0: no log file; 1: summary; 2: moderate; 3: verbose) 
          Default: 0 */
      logFileLevel,
      /** The number of nodes initially generated by the master. 
          Default: 2 */
      masterInitNodeNum,
      /** The interval between master report system status. 
          Default: 10 */
      masterReportInterval,
      /** If the number of processes in a cluster is less than it, the hub
          also work as a worker. 
          Default: 0 (Hub does NOT work) */
      hubWorkClusterSizeLimit,
      /** The size of memory allocated for medium size message.
          Default: 4096 */
      mediumSize,
      /** The level of printing messages on screen. Used to control master and
          general messages.
          (0: no print to screen; 1: summary; 2: moderate; 3: verbose) 
          Default: 2*/
      msgLevel,
      /** The max number of nodes can be processed. 
          Default: ALPS_INT_MAX */
      nodeLimit,
      /** Node log interval. 
          Default: 100 */
      nodeLogInterval,
      /** Print system status: 0: do not print, 1: print.
          Default: 1;*/
      printSystemStatus,
      /** The total number of processes that are launched for parallel code. 
          Default: 2
          Not used since can get actual number of processes from MPI. */
      processNum,
      /** Static load balancing scheme
	  -- root initialization (0)
	  -- spiral (1)
      */
      staticBalanceScheme,
      /** Search strategy
          -- best-first (0)
          -- best-first-estimate (1)
          -- breadth-first (2)
          -- depth-first (3)
          -- hybrid (4)
          Default: hybrid
      */
      searchStrategy,
      searchStrategyRampUp,
      /** The size of memory allocated for small size message. 
          Default: 1024 */
      smallSize, 
      /** The max num of solution can be stored in a solution pool. 
          Default: ALPS_INT_MAX */
      solLimit,
      /** The size/number of nodes of a unit work. 
          Default: 50 */
      unitWorkNodes,
      /** Message level of the worker specific messages. 
          (0: no print to screen; 1: summary; 2: moderate; 3: verbose) 
          Default: 0
      */
      workerMsgLevel,

      threadIndex, 
      ///
      endOfIntParams
  };
  
  /** Double parameters. */
  enum dblParams
  {
      /** The threshold of workload below which a worker will change the subtree
          that is working on. 
          Default: 0.05 */
      changeWorkThreshold,
      /** It is between 1.0 - infty. When the workload in process is more than 
          the average workload timing donorThreshold, it is a donor in load 
          balancing. 
          Defaut: 0.1 */
      donorThreshold,
      /** The time period (sec) for hubs to process messages. 
          Default: 0.1 */
      hubReportPeriod,
      /** The time period for master to do loading balance/termination check. 
          Default: 0.05 */
      masterBalancePeriod,
      /** The threshold of workload below which a process will ask for workload
          Default: 2 */
      needWorkThreshold,
      /** It is between 0.0 - 1.0. When the workload in process is less than 
          the average workload timing receiverThreshold, it is a receiver.
          Default: 0.1 */
      receiverThreshold,
      /** The time limit (in seconds) of search. 
          Default: ALPS_DBL_MAX */
      timeLimit,
      /** The numeric tolerance. 
          Default: 1e-6 */
      tolerance,
      /** The time length of a unit work. 
          Default: 0.5 */
      unitWorkTime, 
      /** If less than this number, it is considered zero workload. 
          Default: 1e-6 */
      zeroLoad,
      /***/
      endOfDblParams
  };

  /** String parameters. */
  enum strParams
  {
      /** The instance to be solved. 
          Default: "NONE" */
      instance,
      /** The name of log file.
          Default: "Alps.log "*/
      logFile,
      ///
      endOfStrParams
  };

  /** There are no string array parameters. */
  enum strArrayParams
  {
      // The dummy is needed so the allocation won't try for 0 entries.
      strArrayDummy,
      ///
      endOfStrArrayParams
  };

 public:

  /**@name Constructors. */
  /*@{*/
  /** The default constructor creates a parameter set with from the template
      argument structure. The keyword list is created and the defaults are
      set. */
  AlpsParams() :
      AlpsParameterSet(
          static_cast<int>(endOfBoolParams),
          static_cast<int>(endOfIntParams),
          static_cast<int>(endOfDblParams),
          static_cast<int>(endOfStrParams),
          static_cast<int>(endOfStrArrayParams)
          )
  {
      createKeywordList();
      setDefaultEntries();
  }
      /*@}*/
      
      virtual ~AlpsParams(){ /**/ }
      
  
      AlpsParams& operator=(const AlpsParams& x) {
          // no need to delete anything, since the size of (almost) everything is
          // the same, just copy over
          // -- The static_cast is needed to satisfy the more picky IBM Visual Age
          //    C++ compiler
          std::copy(x.bpar_, x.bpar_ + static_cast<int>(endOfBoolParams),
                    bpar_);
          std::copy(x.ipar_, x.ipar_ + static_cast<int>(endOfIntParams),
                    ipar_);
          std::copy(x.dpar_, x.dpar_ + static_cast<int>(endOfDblParams),
                    dpar_);
          std::copy(x.spar_, x.spar_ + static_cast<int>(endOfStrParams),
                    spar_);
          std::copy(x.sapar_,
                    x.sapar_ + static_cast<int>(endOfStrArrayParams),
                    sapar_);
          return *this;
      }
      
      /** Method for creating the list of keyword looked for in the parameter
          file. */
      virtual void createKeywordList();
      /** Method for setting the default values for the parameters. */
      virtual void setDefaultEntries();

public:
      //====================================================
      /** For user's application: 
       *    Copy following code exactly (till the end of this class) and 
       *    do NOT change anything. 
       *
       *  The reason can not put following functions in base class 
       *  <CODE> AlpsParameterSet </CODE> is:
       *
       *    <CODE> boolParams </CODE> and <CODE> endOfBoolParams </CODE> etc. 
       *    can NOT be declared in base class. They are different types for
       *    each derived classes.
       */
      //====================================================
 

      /**@name Query methods     
         The members of the parameter set can be queried for using the 
         overloaded entry() method. Using the example in the class
         documentation the user can get a parameter with the
         "<code>param.entry(USER_par::parameter_name)</code>" expression.
      */
      /*@{*/
      ///
      inline bool entry(const boolParams key) const { return bpar_[key]; }
      ///
      inline int entry(const intParams key) const { return ipar_[key]; }
      ///
      inline double entry(const dblParams key) const { return dpar_[key]; }
      ///
      inline const std::string&
          entry(const strParams key) const { return spar_[key]; }
      ///
      inline const std::vector<std::string>&
          entry(const strArrayParams key) const { return sapar_[key]; }
      /*@}*/

      //----------------------------------------------------

      /// char* is true(1) or false(0), not used
      void setEntry(const boolParams key, const char * val) {
		  bpar_[key] = atoi(val) ? true : false; }
      /// char is true(1) or false(0), not used
      void setEntry(const boolParams key, const char val) {
		  bpar_[key] = val ? true : false; }
      /// This method is the one that ever been used.
      void setEntry(const boolParams key, const bool val) {
          bpar_[key] = val; }
      ///
      void setEntry(const intParams key, const char * val) {
          ipar_[key] = atoi(val); }
      ///
      void setEntry(const intParams key, const int val) {
          ipar_[key] = val; }
      ///
      void setEntry(const dblParams key, const char * val) {
          dpar_[key] = atof(val); }
      ///
      void setEntry(const dblParams key, const double val) {
          dpar_[key] = val; }
      ///
      void setEntry(const strParams key, const char * val) {
          spar_[key] = val; }
      ///
      void setEntry(const strArrayParams key, const char *val) {
          sapar_[key].push_back(val); }
      
      //----------------------------------------------------

      /**@name Packing/unpacking methods */
      /*@{*/
      /** Pack the parameter set into buf. */
      void pack(AlpsEncoded& buf) {
          buf.writeRep(bpar_, endOfBoolParams)
              .writeRep(ipar_, endOfIntParams)
              .writeRep(dpar_, endOfDblParams);
          for (int i = 0; i < endOfStrParams; ++i)
              buf.writeRep(spar_[i]);
          for (int i = 0; i < endOfStrArrayParams; ++i) {
              buf.writeRep(sapar_[i].size());
              for (size_t j = 0; j < sapar_[i].size(); ++j)
                  buf.writeRep(sapar_[i][j]);
          }
      }

      /** Unpack the parameter set from buf. */
      void unpack(AlpsEncoded& buf) {
          int dummy;
          // No need to allocate the arrays, they are of fixed length
          dummy = static_cast<int>(endOfBoolParams);
          buf.readRep(bpar_, dummy, false);
          dummy = static_cast<int>(endOfIntParams);
          buf.readRep(ipar_, dummy, false);
          dummy = static_cast<int>(endOfDblParams);
          buf.readRep(dpar_, dummy, false);
          for (int i = 0; i < endOfStrParams; ++i)
              buf.readRep(spar_[i]);
          for (int i = 0; i < endOfStrArrayParams; ++i) {
              size_t str_size;
              buf.readRep(str_size);
              sapar_[i].reserve(str_size);
              for (size_t j = 0; j < str_size; ++j){
                  //	sapar_[i].unchecked_push_back(std::string());
                  sapar_[i].push_back(std::string());
                  buf.readRep(sapar_[i].back());
              }
          }
      }
      /*@}*/
};

#endif

