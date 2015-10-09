#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <random>
#include <time.h>
#include <vector>

class feUtils {
  public:
      std::mt19937 rand;

      feUtils() {
          rand.seed(time(NULL));
          attack = 0;
          hit_rate = 0;
          critical = 0;
          avoid = 0;
          rating = 0;
      }

      feUtils(std::string s) {
          std::seed_seq seed(s.begin(), s.end());
          rand.seed(seed);
          attack = 0;
          hit_rate = 0;
          critical = 0;
          avoid = 0;
          rating = 0;
      }

      int feRNG();

      // For now keeping combat algorithms here - might need to move
      // Observers
      // Returns the final value with all bonuses or debuffs included
      int getAttack() { return attack; }
      int getHitRate() { return hit_rate; }
      int getCritical() { return critical; }
      int getAvoid() { return avoid; }
      int getRating() { return rating; }

      // Mutators
      void setAttack(const std::vector<int>& character_stats);
      void setHitRate(const std::vector<int>& weapon_stats, const char rank, const int buffOrDebuff);
      void setCritical(const std::vector<int>& character_stats);
      void setAvoid(const std::vector<int>& character_stats);
      void setRating(const std::vector<int>& character_stats);
      void resetCombatStats();

  private:
      // Combat Stats
      int attack;
      int hit_rate;
      int critical;
      int avoid;
      int rating;

      // Mutators
      void weaponTriangle(const char rank, const int buffOrDebuff);
      //void weaponRankBonus(const char rank, const & std::string weapon_type);
};

#endif
